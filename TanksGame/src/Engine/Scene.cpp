#include "Scene.h"
#include "Actor.h"
#include "Collider.h"
#include "DynamicArray.h"
#include <string>



Scene::Scene()
{
	m_actors = DynamicArray<Actor*>();
	m_toBeRemoved = DynamicArray<Actor*>();
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

	for (int i = 0; i < m_toBeRemoved.Length(); i++)
	{
		m_actors.Remove(m_toBeRemoved[i]);
	}

	m_toBeRemoved.Clear();

	// check for collision

	for (int row = 0; row < m_actors.Length(); row++)
	{
		for (int column = 0; column < m_actors.Length(); column++)
		{
			if (row == column)
				continue;

			if (m_actors[row]->GetCollider() != nullptr && m_actors[column]->GetCollider() != nullptr)
				if (m_actors[row]->GetCollider()->CheckCollision(m_actors[column]))
				{
					m_actors[column]->OnCollision();
				}
		}
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
	m_toBeRemoved.Add(actor);
}

