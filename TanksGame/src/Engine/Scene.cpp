#include "Scene.h"
#include "Actor.h"
#include "DynamicArray.h"
#include <string>



Scene::Scene()
	 :Scene(){}
	


Scene::~Scene()
{

}

void Scene::Start()
{
	
}

void Scene::Update(double deltaTime)
{
	for (int i = 0; i < _actors.Length(); i++)
	{
		if (!_actors[i].GetStarted())
		{
			_actors[i].Start();
		}
	}
}

void Scene::End()
{
	for (int i = 0; i < _actors.Length(); i++)
	{
		_actors.~DynamicArray();
	}
}

void Scene::AddActor(Actor& actor)
{
	_actors.AddUnique(actor);	
}

void Scene::RemoveActor(Actor& actor)
{
	_actors.Remove(actor);
	return;
}

