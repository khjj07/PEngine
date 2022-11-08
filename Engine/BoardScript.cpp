#include "BoardScript.h"

BoardScript::BoardScript(Transform* t, PointStoneScript* p)
{
	stoneFactory = p;
	transform = t;
}
bool BoardScript::CheckDie(Cell *cell)
{
	bool result = true;
	cell->check = true;
	if (cell->Left)
	{
		if (!cell->Left->stone)
		{
			return false;
		}
		if (!cell->Left->check && cell->Left->color == cell->color)
		{
			result &= CheckDie(cell->Left);
		}
	}
	if (cell->Right)
	{
		if (!cell->Right->stone)
		{
			return false;
		}
		if (!cell->Right->check && cell->Right->color == cell->color)
		{
			result &= CheckDie(cell->Right);
		}
	}
	if (cell->Up)
	{
		if (!cell->Up->stone)
		{
			return false;
		}
		if (!cell->Up->check && cell->Up->color == cell->color)
		{
			result &= CheckDie(cell->Up);
		}
	}
	if (cell->Down)
	{
		if (!cell->Down->stone)
		{
			return false;
		}
		if (!cell->Down->check && cell->Down->color == cell->color)
		{
			result &= CheckDie(cell->Down);
		}
	}
	return result;
}
void BoardScript::KillAllChecked()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (cell[i][j]->check)
			{
				Destroy(cell[i][j]->stone);
				cell[i][j]->stone = nullptr;
				cell[i][j]->check = false;
			}
		}
	}
}
void BoardScript::revertAll()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cell[i][j]->check = false;
		}
	}
}

void BoardScript::UpdateBoard()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (cell[i][j]->stone && !CheckDie(cell[i][j]))
			{
				revertAll();
			}
			else
			{
				KillAllChecked();
			}
		}
	}
}

void BoardScript::Start()
{
	EventHandler board = (EventHandler)[this]() {
		UpdateBoard();
	};
	stoneFactory->stoneCreateEvent.addHandler(board);
	float offset = 50;
	Vector2 size = Vector2(offset * 18, offset * 18);
	LineRenderer* row[19];
	LineRenderer* column[19];
	for (int i = 0; i < 19; i++)
	{
		row[i] = new LineRenderer(Vector2(transform->position.x, transform->position.y + i * offset), Vector2(transform->position.x + size.x, transform->position.y + i * offset));
		column[i] = new LineRenderer(Vector2(transform->position.x + i * offset, transform->position.y), Vector2(transform->position.x + i * offset, transform->position.y + size.y));
		transform->AddComponent(row[i]);
		transform->AddComponent(column[i]);
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cell[i][j] = new Cell();
			cell[i][j]->position = Vector2(transform->position.x + j * offset, transform->position.y + i * offset);
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cell[i][j]->Left = j > 0 ? (cell[i][j - 1]) : nullptr;
			cell[i][j]->Right = j < 19 ? (cell[i][j + 1]) : nullptr;
			cell[i][j]->Up = i > 0 ? (cell[i-1][j]) : nullptr;
			cell[i][j]->Down= i < 19 ? (cell[i+1][j]) : nullptr;
		}
	}

}

void BoardScript::Update(double dt)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			Vector2 mousePos = Input::GetMousePosition();
			if (!cell[i][j]->stone &&Vector2::Distance(cell[i][j]->position, mousePos)<20)
			{
				stoneFactory->target = cell[i][j];
				break;
			}
				
		}
	}
}