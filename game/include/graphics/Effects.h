#pragma once

#include "graphics/Effect.h"

namespace Effects
{
	namespace Transition
	{
		class BlackScreen : public TransitionEffect
		{
		public:
			BlackScreen(float duration = 0.7f) : TransitionEffect(duration)
			{}

			void proceed(Scene* curScene, Scene* newScene, sf::RenderWindow& window) override;
		};
	}
}