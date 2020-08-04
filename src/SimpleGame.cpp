////////////////////////////////////////////////////////////
// Project Simple Game
// Copyright (c) 2020 sk-landry
////////////////////////////////////////////////////////////
#include "SimpleGame.h"
#include "ConstantPool.h"
#include <Nero/scene/CollisionRule.h>

namespace ng
{
	SimpleGame::SimpleGame(nero::Scene::Context context): nero::Scene(context)
		,mPlayer()
		,mPlayerHasKey(false)
		,mPlayerHasTreasure(false)
	{
		//ctr
	}

	SimpleGame::~SimpleGame()
	{
	    //dtr
	}

	void SimpleGame::checkSceneObject()
    {
    	log("checking Scene Objects ...");

    	log("checking World Objects ...");
	    getObjectManager()->checkWorldObject(
	    {
            //list of objects here
	    });

	    log("checking Screen Objects ...");
	    getObjectManager()->checkScreenObject(

	       ScreenPool.startScreen,

	       {
                //list of objects here
	       }
	    );
    }

	sf::Vector2f SimpleGame::getSceneResolution()
	{
        log("Setting up Resolution ...");

	    return sf::Vector2f(1280.f, 720.f);
	}

	void SimpleGame::init()
	{
	    log("SimpleGame Scene v0.1");

	    log("Setting up Collision rules ...");
	    //nero::CollisionRule collisionRule;
	    //collisionRule.canCollide(CategoryPool.player, CategoryPool.ground);
	    //collisionRule.apply(getWorld());

	    log("Setting up the player ...");
    	mPlayer.setObject(getObjectManager()->findObject(ObjectPool.player));

    	//let the camera follow the player
    	setCameraTarget(getObjectManager()->findObject(ObjectPool.player));
	}

    void SimpleGame::handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed)
    {
        mPlayer.handleKeyboardInput(key, isPressed);
    }

    void SimpleGame::handleCollisionContactBegin(nero::Collision collision)
    {
        //Let's grab the key
        if(collision.isObjectCollising(ObjectPool.player, ObjectPool.key))
        {
            //remove the key
            getObjectManager()->removeObject(ObjectPool.key);

            //update boolean
            mPlayerHasKey = true;
        }

        //Open the door
        if(collision.isObjectCollising(ObjectPool.player, ObjectPool.door))
        {
            if(mPlayerHasKey)
            {
                auto doorObject = collision.getObject(ObjectPool.door);
                doorObject->setSensor(true);
            }
        }

        //Grab the treasure
        if(collision.isObjectCollising(ObjectPool.player, ObjectPool.treasure))
        {
            //remove the treasure
            getObjectManager()->removeObject(ObjectPool.treasure);

            //update boolean
            mPlayerHasTreasure = true;

            //let's add a log
            log("game completed ! congratulation !!!");
        }
    }


}
