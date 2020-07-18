////////////////////////////////////////////////////////////
// Project Simple Game
// Copyright (c) 2020 sk-landry
////////////////////////////////////////////////////////////

// The Macro NERO_RENDER_ENGINE allows you to run the DevEngine when CodeBlocks is in Debug Mode
// and the Render Engine CodeBlocks is in Release Mode

#ifndef NERO_RENDER_ENGINE

    #include <Nero/engine/DevEngine.h>
    #include "SimpleGame.h"


    int main()
    {
        nero::DevEngine engine(1900, 990);
            engine.addScene<ng::SimpleGame>("SimpleGame");
        engine.run();

        return 0;
    }

#else

    #include <Nero/engine/RenderEngine.h>
    #include "SimpleGame.h"
    #include "LoadingScreen.h"

    int main()
    {
        auto startupScreen = std::make_shared<ng::LoadingScreen>();

        nero::RenderEngine engine(startupScreen, 1280, 720);
            engine.setScene<ng::SimpleGame>("SimpleGame");
        engine.run();

        return 0;
    }

#endif // NERO_RENDER_ENGINE
