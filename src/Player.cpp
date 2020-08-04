////////////////////////////////////////////////////////////
// Project Simple Game
// Copyright (c) 2020 sk-landry
////////////////////////////////////////////////////////////
#include "Player.h"
#include "ConstantPool.h"
#include <Nero/utility/Utility.h>

namespace ng
{
	Player::Player(): PhysicActionObject()
	{
	    registerAction<nero::MoveAction>(PlayerActionPool.move_left, nero::getMoveLeftAction(150.f));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_right, nero::getMoveRightAction(150.f));
	    registerAction<nero::MoveAction>(PlayerActionPool.move_none, nero::getMoveNoneXAction());
        registerAction<nero::JumpAction>(PlayerActionPool.jump, nero::getJumpAction(1000.f));
	}

	Player::~Player()
	{
	    //dtor
	}

	void Player::setObject(Object::Ptr object)
	{
	    nero::PhysicActionObject::setObject(object);

	    mPhysic     = nero::PhysicObject::Cast(getObject());
	}


	void Player::update(const sf::Time& timeStep)
	{
	    //update parent
	    nero::PhysicActionObject::update(timeStep);
	}

    void Player::handleKeyboardInput(const sf::Keyboard::Key& key, const bool& isPressed)
    {
        //when a key is pressed
        if(isPressed)
        {
            //move left
            if(key == sf::Keyboard::Left)
            {
                moveLeft();
            }
            else if(key == sf::Keyboard::Right)
            {
                moveRight();
            }

            if(key == sf::Keyboard::Up)
            {
                jump();
            }
        }
        //when a key is released
        else
        {
            if(key == sf::Keyboard::Left || key == sf::Keyboard::Right)
            {
                moveNone();
            }
        }
    }

    void Player::moveLeft()
    {
        callAction(PlayerActionPool.move_left);
    }

    void Player::moveRight()
    {
        callAction(PlayerActionPool.move_right);
    }

    void Player::moveNone()
    {
        callAction(PlayerActionPool.move_none);
    }

    void Player::jump()
    {
        callAction(PlayerActionPool.jump);
    }

}



