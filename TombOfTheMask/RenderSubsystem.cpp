#include "RenderSubsystem.h"

RenderSubsystem::RenderSubsystem()
{
}

void RenderSubsystem::BeginPlay()
{
}

void RenderSubsystem::Update()
{
	GWindow->clear();

	for (auto Object : ObjectsToDraw)
	{
		Object->Draw();
	}

	GWindow->display();
}
