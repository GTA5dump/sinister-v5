#include "stdafx.h"
#include "XMLWrapper.h"
#include "XMLWriter.h"

static int getSeconds()
{
	time_t now = time(0);

	struct tm newyear;
	double seconds;

	newyear = *localtime(&now);

	newyear.tm_hour = 0; newyear.tm_min = 0; newyear.tm_sec = 0;
	newyear.tm_mon = 0; newyear.tm_mday = 0;

	seconds = difftime(now, mktime(&newyear));

	return (int)floor(seconds);
}
std::vector <SpawnerStruct>SpawnerObject::Entities;

int SpawnerObject::getNetId(SpawnerId id)
{
	return Entities[id].netId;
}

char* SpawnerObject::getName(SpawnerId id)
{
	return Entities[id].name;
}

Entity SpawnerObject::getEntity(SpawnerId id)
{
	if (!ENTITY::DOES_ENTITY_EXIST(Entities[id].ent) && id != -1)
		Entities[id].ent = NETWORK::NETWORK_GET_ENTITY_FROM_NETWORK_ID(getNetId(id));

	return id == -1 ? players[selfPlayer].ped : Entities[id].ent;
}

bool SpawnerObject::getIdFromEntity(Entity ent, SpawnerId* id)
{
	if (Entities.size() > 0)
	{
		for (int i = 0; i < getSpawnCount(); i++)
		{
			if (getEntity(i) == ent) {
				*id = i;
				return true;
			}
		}
	}
	return false;
}

int SpawnerObject::getSpawnCount()
{
	return Entities.size();
}

Vector3 SpawnerObject::getCoords(SpawnerId id)
{
	return ENTITY::GET_ENTITY_COORDS(getEntity(id), !ENTITY::IS_ENTITY_DEAD(getEntity(id)));
}

Vector3 SpawnerObject::getRotation(SpawnerId id)
{
	return ENTITY::GET_ENTITY_ROTATION(getEntity(id), 2);
}

void SpawnerObject::setCoords(SpawnerId id, Vector3 coords)
{
	if (requestControl(id))
	{
		ENTITY::FREEZE_ENTITY_POSITION(getEntity(id), TRUE);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(getEntity(id), coords.x, coords.y, coords.z, FALSE, FALSE, FALSE);
		ENTITY::FREEZE_ENTITY_POSITION(getEntity(id), getFrozenInPlace(id));
	}
}

void SpawnerObject::setRotation(SpawnerId id, Vector3 rot)
{
	if (requestControl(id))
	{
		ENTITY::SET_ENTITY_ROTATION(getEntity(id), rot.x, rot.y, rot.z, 2, TRUE);
	}
}

bool SpawnerObject::getFrozenInPlace(SpawnerId id)
{
	return Entities[id].toggles.frozenInPlace;
}

void SpawnerObject::freezeInPlace(SpawnerId id, bool freeze)
{
	if (requestControl(id)) {
		ENTITY::SET_ENTITY_DYNAMIC(getEntity(id), !freeze);
		ENTITY::FREEZE_ENTITY_POSITION(getEntity(id), freeze);
		Entities[id].toggles.frozenInPlace = freeze;
		Entities[id].toggles.dynamic = !freeze;
	}
}

bool SpawnerObject::requestControl(SpawnerId id)
{
	if (PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(Entities[id].netId))
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(Entities[id].netId);
	if (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(getEntity(id)))
	{
		for (int i = 0; i < 100; i++)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(getEntity(id));
			if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(getEntity(id)))
				return true;
		}
	}
	else
		return true;
	return false;
}

int SpawnerObject::getHealth(SpawnerId id)
{
	Entities[id].values.health = ENTITY::GET_ENTITY_HEALTH(getEntity(id));
	return Entities[id].values.health;
}

void SpawnerObject::setHealth(SpawnerId id, int health)
{
	if (requestControl(id))
	{
		ENTITY::SET_ENTITY_HEALTH(getEntity(id), health);
	}
}

void SpawnerObject::deleteEntity(SpawnerId id)
{
	if (requestControl(id))
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(getEntity(id), TRUE, TRUE);
		Entity tmp = getEntity(id);
		ENTITY::DELETE_ENTITY(&tmp);
		Entities.erase(Entities.begin() + id);
	}
}

void SpawnerObject::removeEntity(SpawnerId id)
{
	Entity tmp = getEntity(id);
	ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&tmp);
	Entities.erase(Entities.begin() + id);
}

Animation SpawnerObject::getAnimation(SpawnerId id)
{
	return Entities[id].values.anim;
}

void SpawnerObject::setAnimation(SpawnerId id, char* animDict, char* animId, bool inplace)
{
	if (requestControl(id))
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(getEntity(id));
		if (!STREAMING::HAS_ANIM_DICT_LOADED(animDict))
			STREAMING::REQUEST_ANIM_DICT(animDict);
		while (!STREAMING::HAS_ANIM_DICT_LOADED(animDict)) {
			WAIT(0);
		}

		AI::TASK_PLAY_ANIM(getEntity(id), animDict, animId, 1.f, 0.f, -1, 9, 0.f, inplace, inplace, inplace);
		Entities[id].values.anim.dict = animDict;
		Entities[id].values.anim.id = animId;
		Entities[id].values.anim.enabled = true;
		Entities[id].values.anim.inplace = inplace;
		Entities[id].values.scenario.enabled = false;
	}
}

Scenario SpawnerObject::getScenario(SpawnerId id)
{
	return Entities[id].values.scenario;
}

void SpawnerObject::startScenario(SpawnerId id, char* scenario, bool inplace)
{
	if (requestControl(id))
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(getEntity(id));
		Vector3 coords = getCoords(id);
		if (inplace)
			AI::TASK_START_SCENARIO_IN_PLACE(getEntity(id), scenario, 0, TRUE);
		else
			AI::TASK_START_SCENARIO_AT_POSITION(getEntity(id), scenario, coords.x, coords.y, coords.z, getRotation(id).z, 0, FALSE, TRUE);

		Entities[id].values.scenario.enabled = true;
		Entities[id].values.scenario.inplace = inplace;
		Entities[id].values.scenario.scenario = scenario;
	}
}

void SpawnerObject::stopAnimation(SpawnerId id)
{
	if (requestControl(id) && getAnimation(id).enabled)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(getEntity(id));
		Entities[id].values.anim.enabled = false;
	}
}

void SpawnerObject::stopScenario(SpawnerId id)
{
	if (requestControl(id) && getScenario(id).enabled)
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(getEntity(id));
		Entities[id].values.scenario.enabled = false;
	}
}

void SpawnerObject::getClothing(SpawnerId id, int* drawable, int* texture, int* palette)
{
	getEntity(id);
	for (int i = 0; i < 12; i++)
	{
		drawable[i] = PED::GET_PED_DRAWABLE_VARIATION(getEntity(id), i);
		texture[i] = PED::GET_PED_TEXTURE_VARIATION(getEntity(id), i);
		palette[i] = PED::GET_PED_PALETTE_VARIATION(getEntity(id), i);
		Entities[id].values.clothing[0][i] = drawable[i];
		Entities[id].values.clothing[1][i] = texture[i];
		Entities[id].values.clothing[2][i] = palette[i];
	}
}

void SpawnerObject::setClothing(SpawnerId id, int component, int drawable, int texture, int palette)
{
	if (requestControl(id))
	{
		PED::SET_PED_COMPONENT_VARIATION(getEntity(id), component, drawable, texture, palette);
		Entities[id].values.clothing[0][component] = drawable;
		Entities[id].values.clothing[1][component] = texture;
		Entities[id].values.clothing[2][component] = palette;
	}
}

void SpawnerObject::getVehicleMods(SpawnerId id, int* mods)
{
	for (int i = 0; i < 59; i++)
	{
		if (i > VehicleModArmor && i < VehicleModFrontWheels)
			mods[i] = VEHICLE::IS_TOGGLE_MOD_ON(getEntity(id), i);
		else
			mods[i] = VEHICLE::GET_VEHICLE_MOD(getEntity(id), i);
		Entities[id].values.vehicleMods[i] = mods[i];
	}
}

void SpawnerObject::setVehicleMod(SpawnerId id, int type, int value)
{
	if (requestControl(id))
	{
		if (id > VehicleModArmor && id < VehicleModFrontWheels)
			VEHICLE::TOGGLE_VEHICLE_MOD(getEntity(id), type, value);
		else
			VEHICLE::SET_VEHICLE_MOD(getEntity(id), type, value, FALSE);
		Entities[id].values.vehicleMods[type] = value;
	}
}

void SpawnerObject::getVehicleExtras(SpawnerId id, int* extras)
{
	for (int i = 0; i < 11; i++)
	{
		if (VEHICLE::DOES_EXTRA_EXIST(getEntity(id), i))
			extras[i] = VEHICLE::IS_VEHICLE_EXTRA_TURNED_ON(getEntity(id), i);
		else
			extras[i] = -1;
		Entities[id].toggles.vehicleExtras[i] = extras[i];
	}
}

void SpawnerObject::setVehicleExtra(SpawnerId id, int extra, bool value)
{
	if (requestControl(id))
	{
		VEHICLE::SET_VEHICLE_EXTRA(getEntity(id), extra, value);
		Entities[id].toggles.vehicleExtras[extra] = value;
	}
}

void SpawnerObject::setDynamic(SpawnerId id, bool dynamic)
{
	if (requestControl(id))
	{
		ENTITY::FREEZE_ENTITY_POSITION(getEntity(id), !dynamic);
		ENTITY::SET_ENTITY_DYNAMIC(getEntity(id), dynamic);
		Entities[id].toggles.dynamic = dynamic;
		Entities[id].toggles.frozenInPlace = !dynamic;
	}
}

bool SpawnerObject::getDynamic(SpawnerId id)
{
	return Entities[id].toggles.dynamic;
}

void SpawnerObject::setInvincible(SpawnerId id, bool invincible)
{
	if (requestControl(id))
	{
		ENTITY::SET_ENTITY_INVINCIBLE(getEntity(id), invincible);
		Entities[id].toggles.invincible = invincible;
	}
}

bool SpawnerObject::getInvincible(SpawnerId id)
{
	return Entities[id].toggles.invincible;
}

void SpawnerObject::setVisible(SpawnerId id, bool visible)
{
	if (requestControl(id))
	{
		SpawnerId entitiesToDetach[300];
		int attachedEntityCount = getEntitiesAttachedToEntity(id, entitiesToDetach);
		for (int i = 0; i < attachedEntityCount; i++)
		{
			requestControl(getEntity(entitiesToDetach[i]));
			ENTITY::DETACH_ENTITY(getEntity(entitiesToDetach[i]), TRUE, FALSE);
			ENTITY::FREEZE_ENTITY_POSITION(getEntity(entitiesToDetach[i]), TRUE);
		}
		ENTITY::SET_ENTITY_VISIBLE(getEntity(id), visible, TRUE);
		for (int i = 0; i < attachedEntityCount; i++)
		{
			requestControl(getEntity(entitiesToDetach[i]));
			ENTITY::FREEZE_ENTITY_POSITION(getEntity(entitiesToDetach[i]), Entities[entitiesToDetach[i]].toggles.frozenInPlace);
			ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(entitiesToDetach[i]), getEntity(id), Entities[entitiesToDetach[i]].values.attachment.boneIndex, Entities[entitiesToDetach[i]].values.attachment.offset.x, Entities[entitiesToDetach[i]].values.attachment.offset.y, Entities[entitiesToDetach[i]].values.attachment.offset.z, Entities[entitiesToDetach[i]].values.attachment.rot.x, Entities[entitiesToDetach[i]].values.attachment.rot.y, Entities[entitiesToDetach[i]].values.attachment.rot.z, TRUE, FALSE, Entities[entitiesToDetach[i]].toggles.collision, ENTITY::IS_ENTITY_A_PED(getEntity(entitiesToDetach[i])), 0, Entities[entitiesToDetach[i]].values.attachment.fixedRot);
			ENTITY::SET_ENTITY_COLLISION(getEntity(entitiesToDetach[i]), Entities[entitiesToDetach[i]].toggles.collision, TRUE);
		}
		Entities[id].toggles.visible = visible;
	}
}

bool SpawnerObject::getVisible(SpawnerId id)
{
	Entities[id].toggles.visible = ENTITY::IS_ENTITY_VISIBLE(getEntity(id));
	return Entities[id].toggles.visible;
}

int SpawnerObject::getEntitiesAttachedToEntity(SpawnerId id, SpawnerId* entities)
{
	int found = 0;
	for (SpawnerId i = 0; i < getSpawnCount(); i++)
	{
		if (ENTITY::IS_ENTITY_ATTACHED(getEntity(i)))
		{
			if (ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(getEntity(i), getEntity(id)))
			{
				entities[found] = i;
				found++;
			}
		}
	}
	return found;
}

void SpawnerObject::setCollision(SpawnerId id, bool collision)
{
	if (requestControl(id))
	{
		ENTITY::SET_ENTITY_COLLISION(getEntity(id), collision, TRUE);
		Entities[id].toggles.collision = collision;
	}
}

bool SpawnerObject::getCollision(SpawnerId id)
{
	Entities[id].toggles.collision = !ENTITY::_GET_ENTITY_COLLISON_DISABLED(getEntity(id));
	return Entities[id].toggles.collision;
}

rgbi SpawnerObject::getVehiclePrimaryColor(SpawnerId id)
{
	VEHICLE::GET_VEHICLE_CUSTOM_PRIMARY_COLOUR(getEntity(id), &Entities[id].values.vehicleColors.primaryColor.r, &Entities[id].values.vehicleColors.primaryColor.g, &Entities[id].values.vehicleColors.primaryColor.b);
	int nothing;
	VEHICLE::GET_VEHICLE_COLOURS(getEntity(id), &Entities[id].values.vehicleColors.primaryColor.i, &nothing);
	return Entities[id].values.vehicleColors.primaryColor;
}

rgbi SpawnerObject::getVehicleSecondaryColor(SpawnerId id)
{
	VEHICLE::GET_VEHICLE_CUSTOM_SECONDARY_COLOUR(getEntity(id), &Entities[id].values.vehicleColors.secondaryColor.r, &Entities[id].values.vehicleColors.secondaryColor.g, &Entities[id].values.vehicleColors.secondaryColor.b);
	int nothing;
	VEHICLE::GET_VEHICLE_COLOURS(getEntity(id), &nothing, &Entities[id].values.vehicleColors.secondaryColor.i);
	return Entities[id].values.vehicleColors.secondaryColor;
}

void SpawnerObject::setVehicleColors(SpawnerId id, int primaryColor, int secondaryColor, bool primary, bool secondary)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		int orgPrimary;
		int orgSecondary;
		if (primary)
			VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(getEntity(id));
		if (secondary)
			VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(getEntity(id));
		VEHICLE::GET_VEHICLE_COLOURS(getEntity(id), &orgPrimary, &orgSecondary);
		VEHICLE::SET_VEHICLE_COLOURS(getEntity(id), primary ? primaryColor : orgPrimary, secondary ? secondaryColor : orgSecondary);
		if (primary) {
			Entities[id].values.vehicleColors.hasCustomPrimaryColor = false;
			Entities[id].values.vehicleColors.primaryColor.i = primaryColor;
		}
		if (secondary) {
			Entities[id].values.vehicleColors.hasCustomSecondaryColor = false;
			Entities[id].values.vehicleColors.secondaryColor.i = secondaryColor;
		}
	}
}

void SpawnerObject::setVehicleCustomColors(SpawnerId id, rgb primaryColor, rgb secondaryColor, bool primary, bool secondary)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		if (primary) {
			VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(getEntity(id), primaryColor.r, primaryColor.g, primaryColor.b);
			Entities[id].values.vehicleColors.hasCustomPrimaryColor = true;
			getVehiclePrimaryColor(id);
		}
		if (secondary) {
			VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(getEntity(id), secondaryColor.r, secondaryColor.g, secondaryColor.b);
			Entities[id].values.vehicleColors.hasCustomSecondaryColor = true;
			getVehicleSecondaryColor(id);
		}
	}
}

void SpawnerObject::getNeons(SpawnerId id, bool* neons)
{
	for (int i = 0; i < 3; i++)
	{
		neons[i] = VEHICLE::_IS_VEHICLE_NEON_LIGHT_ENABLED(getEntity(id), i);
	}
}

void SpawnerObject::setNeons(SpawnerId id, bool* neons)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		for (int i = 0; i < 3; i++)
		{
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(getEntity(id), i, neons[i]);
			Entities[id].toggles.vehicleNeons[i] = neons[i];
		}
	}
}

rgb SpawnerObject::getNeonColor(SpawnerId id)
{
	rgb color;
	VEHICLE::_GET_VEHICLE_NEON_LIGHTS_COLOUR(getEntity(id), &color.r, &color.g, &color.b);
	Entities[id].values.vehicleColors.neonColor = color;
	return color;
}

void SpawnerObject::setWheelType(SpawnerId id, int type)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(getEntity(id), type);
		Entities[id].values.vehicleWheelType = type;
	}
}

int SpawnerObject::getWheelType(SpawnerId id)
{
	Entities[id].values.vehicleWheelType = VEHICLE::GET_VEHICLE_WHEEL_TYPE(getEntity(id));
	return Entities[id].values.vehicleWheelType;
}

void SpawnerObject::setWheelColor(SpawnerId id, int color)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		int pearlecent;
		int wheels;
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(getEntity(id), &pearlecent, &wheels);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(getEntity(id), pearlecent, color);
		Entities[id].values.vehicleColors.wheelColor = color;
	}
}

int SpawnerObject::getWheelColor(SpawnerId id)
{
	int pearlecent;
	int wheels;
	VEHICLE::GET_VEHICLE_EXTRA_COLOURS(getEntity(id), &pearlecent, &wheels);
	Entities[id].values.vehicleColors.wheelColor = wheels;
	return wheels;
}

void SpawnerObject::setPearlecentColor(SpawnerId id, int color)
{
	if (requestControl(id))
	{
		if (VEHICLE::GET_VEHICLE_MOD_KIT(getEntity(id)) != 0)
			VEHICLE::SET_VEHICLE_MOD_KIT(getEntity(id), 0);
		int pearlecent;
		int wheels;
		VEHICLE::GET_VEHICLE_EXTRA_COLOURS(getEntity(id), &pearlecent, &wheels);
		VEHICLE::SET_VEHICLE_EXTRA_COLOURS(getEntity(id), color, wheels);
		Entities[id].values.vehicleColors.pearlecentColor = color;
	}
}

int SpawnerObject::getPearlecentColor(SpawnerId id)
{
	int pearlecent;
	int wheels;
	VEHICLE::GET_VEHICLE_EXTRA_COLOURS(getEntity(id), &pearlecent, &wheels);
	Entities[id].values.vehicleColors.pearlecentColor = pearlecent;
	return pearlecent;
}

void SpawnerObject::attachToEntity(SpawnerId id, SpawnerId to, Vector3 offsets, Vector3 rot, int boneIndex, bool fixedRot)
{
	if (requestControl(id))
	{
		getCollision(id);
		isPed(id);
		getEntity(id);
		getEntity(to);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(id), getEntity(to), boneIndex, offsets.x, offsets.y, offsets.z, rot.x, rot.y, rot.z, TRUE, FALSE, getCollision(id), isPed(id), 0, fixedRot);
		Entities[id].values.attachment.offset = offsets;
		Entities[id].values.attachment.rot = rot;
		Entities[id].values.attachment.boneIndex = boneIndex;
		Entities[id].values.attachment.fixedRot = fixedRot;
		Entities[id].values.attachment.netId = Entities[to].netId;
	}
}

void SpawnerObject::detachFromEntity(SpawnerId id)
{
	if (requestControl(id))
	{
		ENTITY::DETACH_ENTITY(getEntity(id), FALSE, Entities[id].toggles.collision);
		Entities[id].values.attachment.offset = { 0.f };
		Entities[id].values.attachment.rot = { 0.f };
		Entities[id].values.attachment.boneIndex = 0;
		Entities[id].values.attachment.fixedRot = false;
		Entities[id].values.attachment.netId = 0;
		Entities[id].values.attachment.attached = false;
	}
}

Attachment SpawnerObject::getAttachmentInfo(SpawnerId id)
{
	Entities[id].values.attachment.attached = ENTITY::IS_ENTITY_ATTACHED(getEntity(id));
	if (Entities[id].values.attachment.attached)
	{
		SpawnerId atacchedToNetId;
		if (!getIdFromEntity(ENTITY::GET_ENTITY_ATTACHED_TO(getEntity(id)), &atacchedToNetId) && ENTITY::GET_ENTITY_ATTACHED_TO(getEntity(id)) != players[selfPlayer].ped)
		{
			ENTITY::DETACH_ENTITY(getEntity(id), TRUE, getCollision(id));
			Entities[id].values.attachment.attached = false;
		}
	}
	return Entities[id].values.attachment;
}
bool SpawnerObject::isPed(SpawnerId id)
{
	return ENTITY::IS_ENTITY_A_PED(getEntity(id));
}

bool SpawnerObject::isVehicle(SpawnerId id)
{
	return ENTITY::IS_ENTITY_A_VEHICLE(getEntity(id));
}

bool SpawnerObject::isObject(SpawnerId id)
{
	return ENTITY::IS_ENTITY_AN_OBJECT(getEntity(id));
}

int SpawnerObject::getOpacity(SpawnerId id)
{
	return ENTITY::GET_ENTITY_ALPHA(getEntity(id));
}

void SpawnerObject::getOpacity(SpawnerId id, int alpha)
{
	ENTITY::SET_ENTITY_ALPHA(getEntity(id), alpha, FALSE);
}

void SpawnerObject::setAttachmentOffsets(SpawnerId id, Vector3 offsets)
{
	ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(id), ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(getEntity(id), players[selfPlayer].ped) ? players[selfPlayer].ped : NETWORK::NET_TO_ENT(Entities[id].values.attachment.netId), Entities[id].values.attachment.boneIndex, offsets.x, offsets.y, offsets.z, Entities[id].values.attachment.rot.x, Entities[id].values.attachment.rot.y, Entities[id].values.attachment.rot.z, TRUE, FALSE, getCollision(id), isPed(id), 0, Entities[id].values.attachment.fixedRot);
	Entities[id].values.attachment.offset = offsets;
}

void SpawnerObject::setAttachmentRotation(SpawnerId id, Vector3 rot)
{
	ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(id), ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(getEntity(id), players[selfPlayer].ped) ? players[selfPlayer].ped : NETWORK::NET_TO_ENT(Entities[id].values.attachment.netId), Entities[id].values.attachment.boneIndex, Entities[id].values.attachment.offset.x, Entities[id].values.attachment.offset.y, Entities[id].values.attachment.offset.z, rot.x, rot.y, rot.z, TRUE, FALSE, getCollision(id), isPed(id), 0, Entities[id].values.attachment.fixedRot);
	Entities[id].values.attachment.rot = rot;
}

void SpawnerObject::setFixedAttachmentRot(SpawnerId id, bool fixedRot) {
	ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(id), ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(getEntity(id), players[selfPlayer].ped) ? players[selfPlayer].ped : NETWORK::NET_TO_ENT(Entities[id].values.attachment.netId), Entities[id].values.attachment.boneIndex, Entities[id].values.attachment.offset.x, Entities[id].values.attachment.offset.y, Entities[id].values.attachment.offset.z, Entities[id].values.attachment.rot.x, Entities[id].values.attachment.rot.y, Entities[id].values.attachment.rot.z, TRUE, FALSE, getCollision(id), isPed(id), 0, fixedRot);
	Entities[id].values.attachment.fixedRot = fixedRot;
}

void SpawnerObject::setAttachmentBone(SpawnerId id, int bone) {
	ENTITY::ATTACH_ENTITY_TO_ENTITY(getEntity(id), ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(getEntity(id), players[selfPlayer].ped) ? players[selfPlayer].ped : NETWORK::NET_TO_ENT(Entities[id].values.attachment.netId), bone, Entities[id].values.attachment.offset.x, Entities[id].values.attachment.offset.y, Entities[id].values.attachment.offset.z, Entities[id].values.attachment.rot.x, Entities[id].values.attachment.rot.y, Entities[id].values.attachment.rot.z, TRUE, FALSE, getCollision(id), isPed(id), 0, Entities[id].values.attachment.fixedRot);
	Entities[id].values.attachment.boneIndex = bone;
}

void SpawnerObject::addTask(SpawnerId id, int task, Task args)
{
	args.task = task;
	Entities[id].tasks.tasks.push_back(args);
}

void SpawnerObject::removeTask(SpawnerId id, int taskId)
{
	Entities[id].tasks.tasks.erase(Entities[id].tasks.tasks.begin() + taskId);
}

char* SpawnerObject::getTaskName(int task)
{
	switch (task)
	{
	case 0:
		return "Wait";
	case 1:
		return "Drive To Coords";
	case 2:
		return "Change Drive Style";
	case 3:
		return "Land Plane";
	case 4:
		return "Rappel From Chopper";
	}
	return NULL;
}

bool SpawnerObject::doesTaskExist(int task)
{
	switch (task)
	{
	case 0:
	case 1:
	case 2:
		return true;
	}
	return false;
}

int SpawnerObject::getTask(SpawnerId id, int taskId)
{
	return Entities[id].tasks.tasks[taskId].task;
}

bool SpawnerObject::hasTask(SpawnerId id, int task)
{
	for (int i = 0; i < Entities[id].tasks.tasks.size(); i++)
	{
		if (Entities[id].tasks.tasks[i].task == task)
			return true;
	}
	return false;
}

bool SpawnerObject::isTaskActive(SpawnerId id, int taskId)
{
	if (Entities[id].tasks.tasks[taskId].active)
		return true;
	return false;
}

int SpawnerObject::getActiveTask(SpawnerId id)
{
	return Entities[id].tasks.stage;
}

void SpawnerObject::resetTaskSequince(SpawnerId id)
{
	Entities[id].tasks.stage = 0;
	Entities[id].tasks.startTime = getSeconds();
}

void SpawnerObject::startTask(SpawnerId id, int taskId)
{
	if (!isTaskActive(id, taskId))
	{
		switch (Entities[id].tasks.tasks[taskId].task)
		{
		case 0:
			break;
		case 1:
		{
			if (isPed(id) && getVehicleSeat(id) == -1)
			{
				Vector3 coords = Entities[id].tasks.tasks[taskId].coords;
				AI::TASK_VEHICLE_DRIVE_TO_COORD(getEntity(id), getEntity(getVehicle(id)), coords.x, coords.y, coords.z, Entities[id].tasks.tasks[taskId].vehSpeed, 0, ENTITY::GET_ENTITY_MODEL(getEntity(id)), Entities[id].tasks.tasks[taskId].driveMode, Entities[id].tasks.tasks[taskId].stopRange, 0.f);
			}
			else
			{
				Entities[id].tasks.tasks[taskId].startTime = getSeconds();
				skipCurrentTask(id);
				return;
			}
			break;
		}
		case 2:
		{
			if (isPed(id) && getVehicleSeat(id) == -1)
			{
				AI::SET_DRIVE_TASK_DRIVING_STYLE(getEntity(id), Entities[id].tasks.tasks[taskId].driveMode);
			}
			else
			{
				Entities[id].tasks.tasks[taskId].startTime = getSeconds();
				skipCurrentTask(id);
				return;
			}
		}
		break;
		case 3:
		{
			if (isPed(id) && getVehicleSeat(id) == -1 && VEHICLE::IS_THIS_MODEL_A_PLANE(ENTITY::GET_ENTITY_MODEL(getEntity(getVehicle(id)))))
			{
				Vector3 coords1 = Entities[id].tasks.tasks[taskId].coords;
				Vector3 coords2 = Entities[id].tasks.tasks[taskId].coords2;
				AI::TASK_PLANE_LAND(getEntity(id), getVehicle(id), coords1.x, coords1.y, coords1.z, coords2.x, coords2.y, coords2.z);
			}
			else
			{
				Entities[id].tasks.tasks[taskId].startTime = getSeconds();
				skipCurrentTask(id);
				return;
			}
		}
		break;
		case 4:
		{
			if (isPed(id) && (getVehicleSeat(id) == 1 || getVehicleSeat(id) == 2) && ENTITY::GET_ENTITY_MODEL(getEntity(getVehicle(id))) == $("maverick"))
			{
				AI::TASK_RAPPEL_FROM_HELI(getEntity(id), 1);
			}
			else
			{
				Entities[id].tasks.tasks[taskId].startTime = getSeconds();
				skipCurrentTask(id);
				return;
			}
		}
		break;
		}
		Entities[id].tasks.tasks[taskId].startTime = getSeconds();
		Entities[id].tasks.tasks[taskId].active = true;
	}
	if (Entities[id].tasks.tasks[taskId].duration + Entities[id].tasks.startTime >= getSeconds())
		Entities[id].tasks.stage++;
}

bool SpawnerObject::hasActiveTask(SpawnerId id)
{
	return Entities[id].tasks.active;
}

void SpawnerObject::skipCurrentTask(SpawnerId id)
{
	Entities[id].tasks.startTime += (Entities[id].tasks.tasks[getActiveTask(id)].duration - Entities[id].tasks.tasks[getActiveTask(id)].startTime);
	Entities[id].tasks.tasks[getActiveTask(id)].active = false;
	Entities[id].tasks.stage++;
}

SpawnerId SpawnerObject::getVehicle(SpawnerId id)
{
	getIdFromEntity(PED::GET_VEHICLE_PED_IS_IN(getEntity(id), FALSE), &id);
	return id;
}

int SpawnerObject::getVehicleSeat(SpawnerId id)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(getEntity(id), FALSE))
	{
		for (int i = -2; i < VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(getEntity(getVehicle(id))); i++)
		{
			if (VEHICLE::GET_PED_IN_VEHICLE_SEAT(getEntity(getVehicle(id)), i) == getEntity(id))
				return i;
		}
	}
	return -2;
}

Cam SpawnerObject::movingCam;

void SpawnerObject::moveEntity(SpawnerId id)
{
	if (!CAM::DOES_CAM_EXIST(movingCam)) {
		Vector3 size1, size2;
		GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(getEntity(id)), &size1, &size2);
		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(getEntity(id), 0.f, (size2.y + 2.f), 0.f);
		Vector3 rot = getRotation(id);
		movingCam = CAM::CREATE_CAM_WITH_PARAMS("DEFAULT_SCRIPTED_FLY_CAMERA", coords.x, coords.y, coords.z, 0.f, 0.f, rot.z, 90.f, TRUE, 0);
		CAM::SET_CAM_ACTIVE(movingCam, TRUE);
		CAM::RENDER_SCRIPT_CAMS(TRUE, FALSE, 3000, TRUE, TRUE);
		CAM::ATTACH_CAM_TO_ENTITY(movingCam, getEntity(id), 0.f, -(size2.y * 2.5f), 0.f, TRUE);
	}
	for (;;)
	{
		Vector3 coords = getCoords(id);
		Vector3 rot = getRotation(id);

		Vector3 camRot = CAM::GET_CAM_ROT(movingCam, 2);
		setRotation(id, { 0.f, 0, 0.f, 0, camRot.z });
		float lStickY = CONTROLS::GET_CONTROL_NORMAL(2, ControlFrontendAxisY);
		float lStickX = CONTROLS::GET_CONTROL_NORMAL(2, ControlFrontendAxisX);
		if (!CONTROLS::IS_CONTROL_PRESSED(2, BUTTON_LSTICK))
		{
			Vector3 offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(getEntity(id), 0.f, 2 * -(lStickY), 0.f);
			setCoords(id, offset);
			Vector3 offset2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(getEntity(id), 2 * lStickX, 0.f, 0.f);
			setCoords(id, offset2);
		}
		else
		{
			Vector3 offset3 = getCoords(id);
			offset3.z += 2 * lStickY;
			setCoords(id, offset3);
		}

		if (CONTROLS::IS_CONTROL_PRESSED(2, ControlFrontendAccept))
			break;
		WAIT(0);
	}

	if (CAM::DOES_CAM_EXIST(movingCam)) {
		CAM::DESTROY_CAM(movingCam, TRUE);
		movingCam = NULL;
		CAM::RENDER_SCRIPT_CAMS(FALSE, FALSE, 3000, TRUE, TRUE);
		CAM::SET_CAM_ACTIVE(2, TRUE);
	}
}

bool SpawnerObject::isSaved(SpawnerId id)
{
	return Entities[id].saveInfo.saved;
}

int SpawnerObject::getSaveId(SpawnerId id)
{
	return Entities[id].saveInfo.saveId;
}

SpawnerId SpawnerObject::getIdFromNetId(int netId)
{
	for (int i = 0; i < getSpawnCount(); i++)
	{
		if (Entities[i].netId == netId)
			return i;
	}
}

bool SpawnerObject::getInVehicle(SpawnerId id)
{
	Entities[id].values.vehicle.inVehicle = PED::IS_PED_IN_ANY_VEHICLE(getEntity(id), FALSE);
	return Entities[id].values.vehicle.inVehicle;
}

Hash SpawnerObject::getModel(SpawnerId id)
{
	return ENTITY::GET_ENTITY_MODEL(getEntity(id));
}

int SpawnerObject::getType(SpawnerId id)
{
	if (isVehicle(id))
		return 1;
	if (isPed(id))
		return 2;
	if (isObject(id))
		return 0;
}

void SpawnerObject::startLoopedParticleFX(SpawnerId id, char* ptfxAsset, char* ptfxId)
{
	if (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(ptfxAsset)) {
		STREAMING::REQUEST_NAMED_PTFX_ASSET(ptfxAsset);
		while (!STREAMING::HAS_NAMED_PTFX_ASSET_LOADED(ptfxAsset)) {
			WAIT(0);

		}
	}
	GRAPHICS::_USE_PARTICLE_FX_ASSET_NEXT_CALL(ptfxAsset);
	//Entities[id].values.particle.push_back({ NULL });
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].handle = GRAPHICS::_START_PARTICLE_FX_LOOPED_ON_ENTITY_2(ptfxId, getEntity(id), 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, TRUE, TRUE, TRUE);
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].dict = ptfxAsset;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].id = ptfxId;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].hasParticle = true;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].size = 1.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].rot.x = 0.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].rot.y = 0.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].rot.z = 0.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].offset.x = 0.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].offset.y = 0.f;
	Entities[id].values.particle[Entities[id].values.particle.size() - 1].offset.z = 0.f;
}

void SpawnerObject::setLoopedParticleOffset(SpawnerId id, int particleId, Vector3 offset)
{
	GRAPHICS::SET_PARTICLE_FX_LOOPED_OFFSETS(Entities[id].values.particle[particleId].handle, offset.x, offset.y, offset.z, Entities[id].values.particle[particleId].rot.x, Entities[id].values.particle[particleId].rot.y, Entities[id].values.particle[particleId].rot.z);
	Entities[id].values.particle[particleId].offset = offset;
}

void SpawnerObject::setLoopedParticleRotation(SpawnerId id, int particleId, Vector3 rot)
{
	GRAPHICS::SET_PARTICLE_FX_LOOPED_OFFSETS(Entities[id].values.particle[particleId].handle, Entities[id].values.particle[particleId].offset.x, Entities[id].values.particle[particleId].offset.y, Entities[id].values.particle[particleId].offset.z, rot.x, rot.y, rot.z);
	Entities[id].values.particle[particleId].rot = rot;
}

void SpawnerObject::setLoopedParticleScale(SpawnerId id, int particleId, float size)
{
	GRAPHICS::SET_PARTICLE_FX_LOOPED_SCALE(Entities[id].values.particle[particleId].handle, size);
	Entities[id].values.particle[particleId].size = size;
}

void SpawnerObject::setLoopedParticleColor(SpawnerId id, int particleId, RGBA2 color)
{
	GRAPHICS::SET_PARTICLE_FX_LOOPED_COLOUR(Entities[id].values.particle[particleId].handle, color.r, color.g, color.b, TRUE);
	GRAPHICS::SET_PARTICLE_FX_LOOPED_ALPHA(Entities[id].values.particle[particleId].handle, color.a);
	Entities[id].values.particle[particleId].color = color;
}

void SpawnerObject::deleteLoopedParticle(SpawnerId id, int particleId)
{
	GRAPHICS::REMOVE_PARTICLE_FX(Entities[id].values.particle[particleId].handle, TRUE);
	Entities[id].values.particle.erase(Entities[id].values.particle.begin() + particleId);
}

particle SpawnerObject::getLoopedParticle(SpawnerId id, int particleId)
{
	Entities[id].values.particle[particleId].hasParticle = GRAPHICS::DOES_PARTICLE_FX_LOOPED_EXIST(Entities[id].values.particle[particleId].handle);
	if (!Entities[id].values.particle[particleId].hasParticle) {
		Entities[id].values.particle.erase(Entities[id].values.particle.begin() + particleId);
		return { Entities[id].values.particle[particleId] };
	}
	return Entities[id].values.particle[particleId];
}

int SpawnerObject::getArmor(SpawnerId id) {
	int armor = PED::GET_PED_ARMOUR(getEntity(id));;
	Entities[id].values.armor = armor;
	return armor;
}

void SpawnerObject::setArmor(SpawnerId id, int amount) {
	Entities[id].values.armor = amount;
	PED::SET_PED_ARMOUR(getEntity(id), amount);
}

int SpawnerObject::getMaxArmor(SpawnerId id) {
	return 100;
}

int SpawnerObject::getMaxHealth(SpawnerId id) {
	int maxHealth = PED::GET_PED_MAX_HEALTH(getEntity(id));
	Entities[id].values.maxHealth = maxHealth;
	return maxHealth;
}

void SpawnerObject::setMaxHealth(SpawnerId id, int amount) {
	Entities[id].values.maxHealth = amount;
	PED::SET_PED_MAX_HEALTH(getEntity(id), amount);
}

Proofs SpawnerObject::getProofInfo(SpawnerId id) {
	return Entities[id].values.proofs;
}

void SpawnerObject::setBulletProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.bulletProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setFireProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.fireProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setExplosionProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.explosionProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setCollisionProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.collisionProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setMeleeProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.meleeProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setP6Proof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.p6 = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setP7Proof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.p7 = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

void SpawnerObject::setDownProof(SpawnerId id, bool b00l) {
	Entities[id].values.proofs.downProof = b00l;
	ENTITY::SET_ENTITY_PROOFS(getEntity(id), Entities[id].values.proofs.bulletProof, Entities[id].values.proofs.fireProof, Entities[id].values.proofs.explosionProof, Entities[id].values.proofs.collisionProof, Entities[id].values.proofs.meleeProof, Entities[id].values.proofs.p6, Entities[id].values.proofs.p7, Entities[id].values.proofs.downProof);
}

char* SpawnerObject::getWalkStyle(SpawnerId id) {
	return Entities[id].values.walkStyle;
}

void SpawnerObject::setWalkStyle(SpawnerId id, char* walkStyle) {
	Entities[id].values.walkStyle = walkStyle;
	PED::SET_PED_MOVEMENT_CLIPSET(getEntity(id), walkStyle, 1.f);
}

void SpawnerObject::resetWalkStyle(SpawnerId id) {
	Entities[id].values.walkStyle = NULL;
	PED::RESET_PED_MOVEMENT_CLIPSET(getEntity(id), 1.f);
}
void DrawTriangle(Vector3 coords)
{
	coords.z += 0.5;
	Vector3 triangle1; triangle1.x = coords.x + 0.3f; triangle1.y = coords.y + 0.3f; triangle1.z = coords.z + 2.f;
	Vector3 triangle2; triangle2.x = coords.x - 0.3f; triangle2.y = coords.y + 0.3f; triangle2.z = coords.z + 2.f;
	Vector3 triangle3; triangle3.x = coords.x + 0.3f; triangle3.y = coords.y - 0.3f; triangle3.z = coords.z + 2.f;
	Vector3 triangle4; triangle4.x = coords.x - 0.3f; triangle4.y = coords.y - 0.3f; triangle4.z = coords.z + 2.f;

	GRAPHICS::DRAW_POLY(coords.x, coords.y, coords.z, triangle1.x, triangle1.y, triangle1.z, triangle2.x, triangle2.y, triangle2.z, 255, 150, 20, 255);
	GRAPHICS::DRAW_POLY(coords.x, coords.y, coords.z, triangle2.x, triangle2.y, triangle2.z, triangle3.x, triangle3.y, triangle3.z, 255, 150, 20, 255);
	GRAPHICS::DRAW_POLY(coords.x, coords.y, coords.z, triangle3.x, triangle3.y, triangle3.z, triangle4.x, triangle4.y, triangle4.z, 255, 150, 20, 255);
	GRAPHICS::DRAW_POLY(coords.x, coords.y, coords.z, triangle4.x, triangle4.y, triangle4.z, triangle1.x, triangle1.y, triangle1.z, 255, 150, 20, 255);

	GRAPHICS::DRAW_BOX(triangle1.x, triangle1.y, triangle1.z, triangle4.x, triangle4.y, triangle4.z, 255, 150, 20, 255);
}
void SpawnerObject::highlight(SpawnerId id) {
	Vector3 coords = getCoords(id);
	Vector3 size1, size2;
	GAMEPLAY::GET_MODEL_DIMENSIONS(getModel(id), &size1, &size2);
	coords.z += size2.z;
	DrawTriangle(coords);
}
void Spawner::saveFile(const std::string& spawnerName, int type)
{
	std::string folder = "MapMods";
	switch (type)
	{
	case 1:
	{
		folder = "Vehicles";
		break;
	}
	case 2:
	{
		folder = "Outfits";
		break;
	}
	}
	XMLWriter file;
	file.open("Sinister/Saves/" + folder + "/" + spawnerName + ".sinister");
	file.createNode("SpawnerSettings");
	switch (type)
	{
	case 0:
	{
		file.writeString("Weather", "current");
		file.createInlineValue("TeleportCoords");
		file.addValueToInlineValue<float>("x", 0.f);
		file.addValueToInlineValue<float>("y", 0.f);
		file.addValueToInlineValue<float>("z", 0.f);
		file.endInlineValue();
		file.writeValue<bool>("LoadIPLs", false);
		file.createNode("IPLs");
		file.closeNode();
		file.writeValue<bool>("LoadInteriors", false);
		file.createNode("Interiors");
		file.closeNode();
	}
	break;
	case 1:
	{
		file.writeValue<bool>("AddToDB", true);
		file.writeValue<bool>("TeleportInVehicle", true);
	}
	break;
	case 2:
	{
		file.writeValue<int>("Model", ENTITY::GET_ENTITY_MODEL(players[selfPlayer].ped));
		file.createNode("Clothing");
		int drawable[11];
		int texture[11];
		int palette[11];
		for (int i = 0; i < 12; i++) {
			texture[i] = PED::GET_PED_TEXTURE_VARIATION(players[selfPlayer].ped, i);
			drawable[i] = PED::GET_PED_DRAWABLE_VARIATION(players[selfPlayer].ped, i);
			palette[i] = PED::GET_PED_PALETTE_VARIATION(players[selfPlayer].ped, i);
		}
		for (int i = 0; i < 12; i++)
		{
			file.createInlineValue("_" + std::to_string(i));
			file.addValueToInlineValue<int>("drawable", drawable[i]);
			file.addValueToInlineValue<int>("texture", texture[i]);
			file.addValueToInlineValue<int>("palette", palette[i]);
			file.endInlineValue();
		}
		file.closeNode();
	}
	break;
	}
	file.closeNode();

	file.createNode("SpawnerPlacements");
	int saveCounter = 0;
	for (int loop = 0; loop <50; loop++)
	{
		WAIT(0);
		for (SpawnerId id = 0; id < SpawnerObject::getSpawnCount(); id++)
		{
			if (
				(type == 0 && !SpawnerObject::isSaved(id) && ((SpawnerObject::getAttachmentInfo(id).attached && SpawnerObject::isSaved(SpawnerObject::getIdFromNetId(SpawnerObject::getAttachmentInfo(id).netId))) || !SpawnerObject::getAttachmentInfo(id).attached) && (!SpawnerObject::getInVehicle(id) || (SpawnerObject::isSaved(SpawnerObject::getVehicle(id)))))
				|| (type == 1 && !SpawnerObject::isSaved(id) && ((SpawnerObject::getAttachmentInfo(id).attached && SpawnerObject::isSaved(SpawnerObject::getIdFromNetId(SpawnerObject::getAttachmentInfo(id).netId))) || (!SpawnerObject::getAttachmentInfo(id).attached && PED::IS_PED_IN_VEHICLE(players[selfPlayer].ped, SpawnerObject::getEntity(id), FALSE))) && (!SpawnerObject::getInVehicle(id) || (SpawnerObject::isSaved(SpawnerObject::getVehicle(id)))))
				|| (type == 2 && !SpawnerObject::isSaved(id) && ((SpawnerObject::getAttachmentInfo(id).attached && (SpawnerObject::isSaved(SpawnerObject::getIdFromNetId(SpawnerObject::getAttachmentInfo(id).netId)) || ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(SpawnerObject::getEntity(id), players[selfPlayer].ped)))) && (!SpawnerObject::getInVehicle(id) || (SpawnerObject::isSaved(SpawnerObject::getVehicle(id)))))
				)
			{
				file.createNode("SpawnerObject");
				file.writeValue<int>("Model", SpawnerObject::getModel(id));
				file.writeString("Name", SpawnerObject::getName(id));
				file.writeValue<int>("Type", SpawnerObject::getType(id));
				file.writeValue<int>("Id", SpawnerObject::getSaveId(id));
				file.writeValue<bool>("Invincible", SpawnerObject::getInvincible(id));
				file.writeValue<bool>("Collision", SpawnerObject::getCollision(id));
				file.writeValue<bool>("Visible", SpawnerObject::getVisible(id));
				file.writeValue<bool>("Dynamic", SpawnerObject::getDynamic(id));
				file.writeValue<bool>("Frozen", SpawnerObject::getFrozenInPlace(id));
				file.writeValue<int>("Health", SpawnerObject::getHealth(id));
				file.writeValue<int>("MaxHealth", SpawnerObject::getMaxHealth(id));
				if (SpawnerObject::isPed(id)) {
					file.writeValue<int>("Armor", SpawnerObject::getArmor(id));
				}
				file.writeValue<int>("Opacity", SpawnerObject::getOpacity(id));
				file.createInlineValue("Coords");
				file.addValueToInlineValue<float>("x", SpawnerObject::getCoords(id).x);
				file.addValueToInlineValue<float>("y", SpawnerObject::getCoords(id).y);
				file.addValueToInlineValue<float>("z", SpawnerObject::getCoords(id).z);
				file.endInlineValue();
				file.createInlineValue("Rotation");
				file.addValueToInlineValue<float>("x", SpawnerObject::getRotation(id).x);
				file.addValueToInlineValue<float>("y", SpawnerObject::getRotation(id).y);
				file.addValueToInlineValue<float>("z", SpawnerObject::getRotation(id).z);
				file.endInlineValue();
				file.writeValue<bool>("Attached", SpawnerObject::getAttachmentInfo(id).attached);
				if (SpawnerObject::getAttachmentInfo(id).attached)
				{
					file.createNode("Attachment");
					file.writeValue<int>("AttachedTo", ENTITY::IS_ENTITY_ATTACHED_TO_ENTITY(SpawnerObject::getEntity(id), players[selfPlayer].ped) ? -1 : SpawnerObject::getSaveId(SpawnerObject::getIdFromNetId(SpawnerObject::getAttachmentInfo(id).netId)));
					file.createInlineValue("Coords");
					file.addValueToInlineValue<float>("x", SpawnerObject::getAttachmentInfo(id).offset.x);
					file.addValueToInlineValue<float>("y", SpawnerObject::getAttachmentInfo(id).offset.y);
					file.addValueToInlineValue<float>("z", SpawnerObject::getAttachmentInfo(id).offset.z);
					file.endInlineValue();
					file.createInlineValue("Rotation");
					file.addValueToInlineValue<float>("x", SpawnerObject::getAttachmentInfo(id).rot.x);
					file.addValueToInlineValue<float>("y", SpawnerObject::getAttachmentInfo(id).rot.y);
					file.addValueToInlineValue<float>("z", SpawnerObject::getAttachmentInfo(id).rot.z);
					file.endInlineValue();
					file.writeValue<bool>("FixedRotation", SpawnerObject::getAttachmentInfo(id).fixedRot);
					file.writeValue<int>("BoneIndex", SpawnerObject::getAttachmentInfo(id).boneIndex);
					file.closeNode();
				}
				if (SpawnerObject::getType(id) == 1)
				{
					file.createNode("Colors");
					rgbi primaryColor = SpawnerObject::getVehiclePrimaryColor(id);
					rgbi secondaryColor = SpawnerObject::getVehicleSecondaryColor(id);
					file.writeValue("Primary", primaryColor.i);
					file.writeValue("Secondary", secondaryColor.i);
					file.createInlineValue("CustomPrimary");
					file.addValueToInlineValue<int>("r", primaryColor.r);
					file.addValueToInlineValue<int>("g", primaryColor.g);
					file.addValueToInlineValue<int>("b", primaryColor.b);
					file.endInlineValue();
					file.createInlineValue("CustomSecondary");
					file.addValueToInlineValue<int>("r", secondaryColor.r);
					file.addValueToInlineValue<int>("g", secondaryColor.g);
					file.addValueToInlineValue<int>("b", secondaryColor.b);
					file.endInlineValue();
					file.writeValue<int>("Pearlecent", SpawnerObject::getPearlecentColor(id));
					file.closeNode();
					file.createNode("Wheels");
					file.writeValue<int>("WheelType", SpawnerObject::getWheelType(id));
					file.writeValue("Color", SpawnerObject::getWheelColor(id));
					file.closeNode();
					file.createNode("VehicleMods");
					int mods[60];
					SpawnerObject::getVehicleMods(id, mods);
					for (int i = 0; i <60; i++)
					{
						file.writeValue<int>("_" + std::to_string(i), mods[i]);
					}
					file.closeNode();
					int extras[12];
					SpawnerObject::getVehicleExtras(id, extras);
					file.createNode("Extras");
					for (int i = 0; i < 12; i++)
					{
						file.writeValue<int>("_" + std::to_string(i), extras[i]);
					}
					file.closeNode();
					file.createNode("Neon");
					bool neons[4];
					SpawnerObject::getNeons(id, neons);
					for (int i = 0; i < 4; i++) {
						file.writeValue<bool>("Neon" + std::to_string(i), neons[i]);
					}
					file.createInlineValue("Color");
					rgb color = SpawnerObject::getNeonColor(id);
					file.addValueToInlineValue<int>("r", color.r);
					file.addValueToInlineValue<int>("g", color.g);
					file.addStringToInlineValue<int>("b", color.b);
					file.closeNode();
				}
				if (SpawnerObject::getType(id) == 2)
				{
					int drawable[11];
					int texture[11];
					int palette[11];
					SpawnerObject::getClothing(id, drawable, texture, palette);
					file.createNode("Clothing");
					for (int i = 0; i < 12; i++)
					{
						file.createInlineValue("_" + std::to_string(i));
						file.addValueToInlineValue<int>("Drawable", drawable[i]);
						file.addValueToInlineValue<int>("Texture", texture[i]);
						file.addValueToInlineValue<int>("palette", palette[i]);
						file.endInlineValue();
					}
					file.closeNode();
					file.writeValue<bool>("HasAnimation", SpawnerObject::getAnimation(id).enabled);
					if (SpawnerObject::getAnimation(id).enabled)
					{
						file.createNode("Animation");
						file.writeString("Dict", SpawnerObject::getAnimation(id).dict);
						file.writeString("Id", SpawnerObject::getAnimation(id).id);
						file.writeValue<bool>("Inplace", SpawnerObject::getAnimation(id).inplace);
						file.closeNode();
					}
					file.writeValue<bool>("HasScenario", SpawnerObject::getScenario(id).enabled);
					if (SpawnerObject::getScenario(id).enabled)
					{
						file.createNode("Scenario");
						file.writeString("Id", SpawnerObject::getScenario(id).scenario);
						file.writeValue<bool>("Inplace", SpawnerObject::getScenario(id).inplace);
						file.closeNode();
					}
					file.writeValue<bool>("InVehicle", SpawnerObject::getInVehicle(id));
					if (SpawnerObject::getInVehicle(id))
					{
						file.createNode("VehicleToSpawnIn");
						file.writeValue<int>("Id", SpawnerObject::getSaveId(SpawnerObject::getIdFromNetId(SpawnerObject::getVehicle(id))));
						file.writeValue<int>("Seat", SpawnerObject::getVehicleSeat(id));
						file.closeNode();
					}
				}
				file.closeNode();
				Entities[id].saveInfo.saved = true;
				Entities[id].saveInfo.saveId = saveCounter;
				saveCounter++;
			}
		}
	}
	file.closeNode();
	file.close();

	for (int i = 0; i < SpawnerObject::getSpawnCount(); i++)
		Entities[i].saveInfo.saved = false;
}
void MaxUpgrade(Vehicle veh)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(veh, 0);

	VEHICLE::SET_VEHICLE_WHEEL_TYPE(veh, VehicleWheelTypeHighEnd);

	for (int i = 60; i--;)
	{
		if (i > VehicleModArmor && i < VehicleModFrontWheels)
			VEHICLE::TOGGLE_VEHICLE_MOD(veh, i, TRUE);
		else
			VEHICLE::SET_VEHICLE_MOD(veh, i, VEHICLE::GET_NUM_VEHICLE_MODS(veh, i) - 1, TRUE);
	}

	VEHICLE::SET_VEHICLE_MOD(veh, VehicleModHorns, 1, FALSE);

	for (int i = 3; i--;)
		VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(veh, i, TRUE);

	VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh, 0, 0);
	/*VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(veh, Menu::titleText.r, Menu::titleText.g, Menu::titleText.b);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(veh, VehicleWindowTintLimo);
	VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(veh, Menu::titleText.r, Menu::titleText.g, Menu::titleText.b);
	VEHICLE::SET_VEHICLE_COLOURS(veh, VehicleColorMettalicBlackBlue, VehicleColorMettalicBlackBlue);
	VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, Menu::titleRect.r, Menu::titleRect.g, Menu::titleRect.b);
	VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh, Menu::titleText.r, Menu::titleText.g, Menu::titleText.b);*/

	for (int i = 12; i--;)
	{
		if (VEHICLE::DOES_EXTRA_EXIST(veh, i))
			VEHICLE::SET_VEHICLE_EXTRA(veh, i, FALSE);
	}


}
int Spawner::spawnEntity(char* entity, int type, Vector3 coords, float heading, bool maxVehicle) {
	Entity ent;
	int netId;
	
	switch (type) {
	case 0:
	{
		ent = OBJECT::CREATE_OBJECT($(entity), coords.x, coords.y, coords.z, TRUE, TRUE, TRUE);
		ENTITY::SET_ENTITY_HEADING(ent, heading);
		netId = NETWORK::OBJ_TO_NET(ent);
	}
	break;
	case 1:
	{
		STREAMING::REQUEST_MODEL($(entity));
		while (!STREAMING::HAS_MODEL_LOADED($(entity)))
			WAIT(0);
		ent = VEHICLE::CREATE_VEHICLE($(entity), coords.x, coords.y, coords.z, heading, TRUE, TRUE);
		netId = NETWORK::VEH_TO_NET(ent);
		if (maxVehicle)
			MaxUpgrade(ent);
		DECORATOR::DECOR_REGISTER("Player_Vehicle", 3);
		DECORATOR::DECOR_REGISTER("PV_Slot", 3);
		DECORATOR::DECOR_REGISTER("Veh_Modded_By_Player", 3);
		DECORATOR::DECOR_SET_INT(ent, "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(selfPlayer));
		DECORATOR::DECOR_SET_INT(ent, "Veh_Modded_By_Player", GAMEPLAY::GET_HASH_KEY(PLAYER::GET_PLAYER_NAME(selfPlayer)));
		DECORATOR::DECOR_SET_INT(ent, "Not_Allow_As_Saved_Veh", 0);
		DECORATOR::DECOR_SET_BOOL(ent, "IgnoredByQuickSave", 0);
		int var;
		if (DECORATOR::DECOR_EXIST_ON(ent, "MPBitset"))
		{
			var = DECORATOR::DECOR_GET_INT(ent, "MPBitset");
		}
		GAMEPLAY::SET_BIT(&var, 3);
		DECORATOR::DECOR_SET_INT(ent, "MPBitset", var);
		VEHICLE::SET_VEHICLE_IS_STOLEN(ent, false);
		if (!Hooking::stat_get_int(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), &ent, 1))
		{
			Hooking::stat_set_int(GAMEPLAY::GET_HASH_KEY("MPPLY_VEHICLE_ID_ADMIN_WEB"), ent, 1);
		}
	}
	break;
	case 2:
	{
		STREAMING::REQUEST_MODEL($(entity));
		while (!STREAMING::HAS_MODEL_LOADED($(entity)))
			WAIT(0);
		ent = PED::CREATE_PED(0, $(entity), coords.x, coords.y, coords.z, heading, TRUE, TRUE);
		netId = NETWORK::PED_TO_NET(ent);
	}
	break;
	}

	if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(netId)) {
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(netId, TRUE);
		ENTITY::SET_ENTITY_ALWAYS_PRERENDER(ent, TRUE);
	}

	while (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(ent)) {
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(ent, FALSE, TRUE);
	}

	SpawnerStruct tmp;
	tmp.name = entity;
	tmp.netId = netId;
	tmp.ent = ent;
	SpawnerObject::Entities.push_back(tmp);
	SpawnerObject::getCoords(SpawnerObject::Entities.size() - 1);
	SpawnerObject::getRotation(SpawnerObject::Entities.size() - 1);

	ENTITY::SET_ENTITY_LOD_DIST(ent, 16960);

	return SpawnerObject::Entities.size() - 1;
}
void Teleport(Vector3 coords, bool notification)
{

	typedef bool(__fastcall * tpos)(int entity, Vector3 pos,
		BOOL xAxis, BOOL yAxis, BOOL zAxis, BOOL clearArea);

	tpos setpos = (tpos)(Memory::pattern("F3 0F 10 3A F3 44 0F 10 42 ? F3 0F 10 72 ? 44 0F 29 58").count(1).get(0).get<void>(-0x3D));

	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), FALSE))
	{
		RequestControlOfEnt(players[selfPlayer].veh);
	}
	setpos(players[selfPlayer].inVehicle ? players[selfPlayer].veh : players[selfPlayer].ped, { coords.x, 0x0,coords.y,0x0, coords.z,0x0 }, TRUE, TRUE, TRUE, FALSE);
	//if (notification) {
	//if (sameVec(ENTITY::GET_ENTITY_COORDS(players[selfPlayer].ped, TRUE), coords, false, 1.f))
	//UI::MessageAtBottomScreen("You have been teleported", 2000);
	//else
	//UI::MessageAtBottomScreen("~r~Failed to teleport you", 2000);
}
void changeModelHash(Hash model)
{
	if (!STREAMING::HAS_MODEL_LOADED((model)))
		STREAMING::REQUEST_MODEL((model));
	while (!STREAMING::HAS_MODEL_LOADED((model))) {
		WAIT(0);
	}

	PLAYER::SET_PLAYER_MODEL(selfPlayer, (model));
	//UI::MessageAtBottomScreen(Menu::StringToChar("Your model has been changed to " + std::to_string(model)), 2000);
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED((model));
}
void Spawner::loadFile(std::string name, int type) {

	CAM::DO_SCREEN_FADE_OUT(200);

	int origEntityCount = SpawnerObject::getSpawnCount();

	std::vector <bool> dynamic;
	std::vector <bool> collision;

	std::string folder = "MapMods";
	switch (type)
	{
	case 1:
	{
		folder = "Vehicles";
		break;
	}
	case 2:
	{
		folder = "Outfits";
		break;
	}
	}
	XML file;
	file.open("Sinister/Saves/" + folder + "/" + name);

	bool tpInVehicle = false;
	file.openNode("SpawnerSettings");
	switch (type) {
	case 0: {
		if (std::string(file.getChar("Weather")).compare("current") != 0) {
			GAMEPLAY::SET_WEATHER_TYPE_PERSIST(file.getChar("Weather"));
		}
		file.openInlineValue("TeleportCoords");
		Teleport({ file.getInlineFloat("x"), 0, file.getInlineFloat("y"), 0, file.getInlineFloat("z"), 0 }, false);
	}
			break;
	case 1: {
		tpInVehicle = file.getBool("TeleportInVehicle");
	}
			break;
	case 2: {
		changeModelHash(file.getInt("Model"));
		file.openNode("Clothing");
		for (int i = 0; i < 12; i++) {
			file.openInlineValue(std::string("_" + std::to_string(i)).c_str());
			PED::SET_PED_COMPONENT_VARIATION(players[selfPlayer].ped, i, file.getInlineInt("drawable"), file.getInlineInt("texture"), file.getInlineInt("palette"));
		}
		file.closeNode();
	}
			break;
	}
	file.closeNode();

	file.openNode("SpawnerPlacements");

	pugi::xml_node tmp = file.getCurrentNode();
	for (pugi::xml_node_iterator it = tmp.begin(); it != tmp.end(); ++it) {
		file.addNodeToStack(it.get_xml_node());

		Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(players[selfPlayer].ped, 0.f, 5.f, 0.f);
		if (type == 0) {
			file.openInlineValue("Coords");
			coords.x = file.getInlineFloat("x");
			coords.y = file.getInlineFloat("y");
			coords.z = file.getInlineFloat("z");
		}
		SpawnerId id = Spawner::spawnEntity(file.getChar("Name"), file.getInt("Type"), coords, 0.f, false);
		SpawnerObject::setCollision(id, false);
		SpawnerObject::freezeInPlace(id, true);
		SpawnerObject::setMaxHealth(id, file.getInt("MaxHealth"));
		Vector3 rot = { 0 };
		if (type == 0) {
			file.openInlineValue("Rotation");
			rot.x = file.getInlineFloat("x");
			rot.y = file.getInlineFloat("y");
			rot.z = file.getInlineFloat("z");
		}
		else
			rot.z = ENTITY::GET_ENTITY_HEADING(players[selfPlayer].ped);
		SpawnerObject::setRotation(id, rot);
		SpawnerObject::setHealth(id, file.getInt("Health"));
		SpawnerObject::setInvincible(id, file.getBool("Invincible"));
		dynamic.push_back(file.getBool("Dynamic"));
		collision.push_back(file.getBool("Collision"));
		SpawnerObject::setVisible(id, file.getBool("Visible"));

		if (file.getBool("Attached")) {
			file.openNode("Attachment");
			Vector3 acoords;
			file.openInlineValue("Coords");
			acoords.x = file.getInlineFloat("x");
			acoords.y = file.getInlineFloat("y");
			acoords.z = file.getInlineFloat("z");
			Vector3 arot;
			file.openInlineValue("Rotation");
			arot.x = file.getInlineFloat("x");
			arot.y = file.getInlineFloat("y");
			arot.z = file.getInlineFloat("z");
			SpawnerObject::attachToEntity(id, file.getInt("AttachedTo") == -1 ? -1 : origEntityCount + file.getInt("AttachedTo"), acoords, arot, file.getInt("BoneIndex"), file.getBool("FixedRotation"));
			Log::Msg(std::to_string(file.getInt("AttachedTo")).c_str());
			file.closeNode();
		}
		else if (type == 1) {
			if (tpInVehicle) {
				PED::SET_PED_INTO_VEHICLE(players[selfPlayer].ped, getEntity(id), -1);
			}
		}

		switch (file.getInt("Type")) {
		case 0:
			//Nothing yet
			break;
		case 1:
		{
			file.openNode("Colors");
			SpawnerObject::setVehicleColors(id, file.getInt("Primary"), file.getInt("Secondary"), true, true);
			rgb primColor;
			file.openInlineValue("CustomPrimary");
			primColor.r = file.getInlineInt("r");
			primColor.g = file.getInlineInt("g");
			primColor.b = file.getInlineInt("b");
			rgb secColor;
			file.openInlineValue("CustomSecondary");
			secColor.r = file.getInlineInt("r");
			secColor.g = file.getInlineInt("g");
			secColor.b = file.getInlineInt("b");
			SpawnerObject::setVehicleCustomColors(id, primColor, secColor, true, true);
			SpawnerObject::setPearlecentColor(id, file.getInt("Pearlecent"));
			file.closeNode();

			file.openNode("Wheels");
			SpawnerObject::setWheelType(id, file.getInt("WheelType"));
			SpawnerObject::setWheelColor(id, file.getInt("Color"));
			file.closeNode();

			file.openNode("VehicleMods");
			for (int i = 0; i < 60; i++) {
				SpawnerObject::setVehicleMod(id, i, file.getInt(std::string("_" + std::to_string(i)).c_str()));
			}
			file.closeNode();

			file.openNode("Extras");
			for (int i = 0; i < 12; i++) {
				SpawnerObject::setVehicleExtra(id, i, file.getBool(std::string("_" + std::to_string(i)).c_str()));
			}
			file.closeNode();
		}
		break;
		case 2:
		{
			SpawnerObject::setArmor(id, file.getInt("Armor"));

			file.openNode("Clothing");
			for (int i = 0; i < 12; i++) {
				file.openInlineValue(std::string("_" + std::to_string(i)).c_str());
				SpawnerObject::setClothing(id, i, file.getInlineInt("Drawable"), file.getInlineInt("Texture"), file.getInlineInt("palette"));
			}
			file.closeNode();
			if (file.getBool("HasAnimation")) {
				file.openNode("Animation");
				SpawnerObject::setAnimation(id, file.getChar("Dict"), file.getChar("Id"), file.getBool("InPlace"));
				file.closeNode();
			}
			else if (file.getBool("HasScenario")) {
				file.openNode("Scenario");
				SpawnerObject::startScenario(id, file.getChar("Id"), file.getBool("Inplace"));
				file.closeNode();
			}
		}
		break;
		}

		file.closeNode();
	}

	file.closeNode();

	for (int i = origEntityCount; i < SpawnerObject::getSpawnCount(); i++) {
		SpawnerObject::setDynamic(i, dynamic[i - origEntityCount]);
		SpawnerObject::setCollision(i, collision[i - origEntityCount]);
	}

	CAM::DO_SCREEN_FADE_IN(200);
}

void Spawner::deleteAllEntities() {
	int tmp = SpawnerObject::Entities.size();
	for (SpawnerId id = 0; id < tmp; id++) {
		SpawnerObject::deleteEntity(id);
	}
}

void Spawner::removeAllEntities() {
	int tmp = SpawnerObject::Entities.size();
	for (SpawnerId id = 0; id < tmp; id++) {
		SpawnerObject::removeEntity(id);
	}
}

bool Spawner::isFreeCamActive() {
	return freeCam;
}

bool Spawner::freeCam = false;











int convertToMenyooType(int type) {
	switch (type) {
	case 0:
		return 0;
	case 1:
		return 1;
	case 3:
		return 0;
	}
}

void Spawner::loadMayoFile(std::string name) {
	XML file;
	file.open(name);

	int origSpawnCount = SpawnerObject::getSpawnCount();

	file.openNode("SpoonerPlacements");

	std::vector<bool> dynamic;
	std::vector<bool> collision;

	pugi::xml_node tmp;
	for (pugi::xml_node_iterator it = tmp.begin(); it != tmp.end(); ++it) {
		file.addNodeToStack(it.get_xml_node());

		Vector3 spawnCoords;
		Vector3 spawnRot;
		file.openNode("PositionRotation");
		spawnCoords.x = file.getFloat("X");
		spawnCoords.y = file.getFloat("Y");
		spawnCoords.z = file.getFloat("Z");
		spawnRot.x = file.getFloat("Pitch");
		spawnRot.y = file.getFloat("Roll");
		spawnRot.z = file.getFloat("Yaw");
		file.closeNode();

		SpawnerId id = Spawner::spawnEntity(file.getChar("HashName"), convertToMenyooType(file.getInt("Type")), spawnCoords, spawnRot.z, false);

		SpawnerObject::setCollision(id, false);
		SpawnerObject::freezeInPlace(id, true);

		dynamic.push_back(file.getBool("FrozenPos"));
		collision.push_back(!file.getBool("IsCollisionProof"));

		SpawnerObject::setMaxHealth(id, file.getInt("MaxHealth"));
		SpawnerObject::setHealth(id, file.getInt("Health"));

		SpawnerObject::setInvincible(id, file.getBool("IsInvincible"));

		SpawnerObject::setRotation(id, spawnRot);

		WAIT(0);
	}

	for (int i = 0; i < dynamic.size(); i++) {
		SpawnerObject::setDynamic(i + origSpawnCount - 1, dynamic[i]);
		SpawnerObject::setDynamic(i + origSpawnCount - 1, collision[i]);
	}
}
