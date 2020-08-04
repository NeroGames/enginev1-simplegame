////////////////////////////////////////////////////////////
// Project Simple Game
// Copyright (c) 2020 sk-landry
////////////////////////////////////////////////////////////
#ifndef SIMPLEGAME_H
#define SIMPLEGAME_H

#include <Nero/scene/Scene.h>
#include "Player.h"

namespace ng
{
	class SimpleGame : public nero::Scene
	{
	    public:
	                            SimpleGame(nero::Scene::Context context);
	        virtual            ~SimpleGame();

	    protected:
	        void                init();
			void                checkSceneObject();
			sf::Vector2f		getSceneResolution();
            void                handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed);
            void                handleCollisionContactBegin(nero::Collision collision);


	    private:
        	Player		        mPlayer;
        	bool                mPlayerHasKey;
        	bool                mPlayerHasTreasure;
	};
}


#endif // SIMPLEGAME_H
