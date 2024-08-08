#include "Room.h"

Room::Room() : objects()
{
}

Room::~Room()
{
    for (auto *object : objects)
        delete object;
    objects.clear(); // ain't nobody got time for nullptrs
}

void Room::Step()
{
    for (auto *object : objects)
        object->Step();
}

void Room::Draw()
{
    for (auto *object : objects)
        object->Draw();
}

void Room::AddObject(GameObject *object) { objects.push_back(object); }