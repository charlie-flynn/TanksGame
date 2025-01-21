#include "Scene.h"
#include "Actor.h"
#include "DynamicArray.h"
#include <string>



Scene::Scene()
{
	m_actors = DynamicArray<Actor*>();
}
	


Scene::~Scene()
{
	m_actors.Clear();
}

void Scene::Start()
{
	m_actors.Begin();
}

void Scene::Update(double deltaTime)
{
	for (int i = 0; i < m_actors.Length(); i++)
	{
		if (!m_actors[i]->GetStarted())
		{
			m_actors[i]->Start();
		}
		m_actors[i]->Update(deltaTime);
	}
}

void Scene::End()
{
	for (int i = 0; i < m_actors.Length(); i++)
	{
		m_actors[i]->Destroy(m_actors[i]);
	}
}

void Scene::AddActor(Actor* actor)
{
	m_actors.Add(actor);	
}

void Scene::RemoveActor(Actor* actor)
{
	m_actors.Remove(actor);
	return;
}

