#include "MainGame.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::init()
{
	SDL_Init(SDL_INIT_HAPTIC | SDL_INIT_CAMERA | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Hola", width, height, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();

	if (error != GLEW_OK) {
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
	initShaders();
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			gameState = GameState::EXIT;
			break;
		
		case SDL_EVENT_MOUSE_MOTION:
			inputManager.setMouseCoords(event.motion.x, event.motion.y);

			//cout << "posicion x " << event.motion.x << " posicion y " << event.motion.y << endl;
			break;

		case SDL_EVENT_KEY_DOWN:
			inputManager.pressKey(event.key.key);

			break;

		case SDL_EVENT_KEY_UP:
			inputManager.releaseKey(event.key.key);
			break;
		default:
			break;
		}
	}
}

void MainGame::initShaders() {
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAtribute("vertexPosition");
	program.addAtribute("vertexColor");
	program.addAtribute("vertexUV");
	program.linkShader();
}

void MainGame::run()
{
	/* 
	
	Para agregar imagenes en diferentes posiciones
	se va trabajar con sprites.push_back para setear el sprite
	y se trabajara con sprites.back()-> init( x, y, w, h, img)
	los valores x, y varian entre -1, 0 para la posicion. Ejm.

			   x   x
		      -1   0
			  _______
		y  0 | a | b |        ( -1,  0 )  ( 0, 0 )
		     |___|___|   ==>
		y -1 | c | d |		  ( -1, -1 )  ( 0, -1)
		     |___|___|
	*/
	
	width = 800;
	height = 600;

	gameState = GameState::PLAY;

	init();
	
	sprites.push_back(new Sprite());
	sprites.back()->init(-1, -1, 1, 1, "images/image.png");


	sprites.push_back(new Sprite());
	sprites.back()->init(0, -1, 1, 1, "images/image.png");

	sprites.push_back(new Sprite());
	sprites.back()->init(0, 0, 1, 1, "images/image.png");

	sprites.push_back(new Sprite());
	sprites.back()->init(-1, 0, 1, 1, "images/image.png");

	//sprite.init(-1, -1, 1, 1, "images/image.png");
	update();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}

void MainGame::draw()
{
	time += 0.0002;
	glClearDepth(1.0);

	//GL_COLOR_BUFFER_BIT = 0x00004000; A
	//GL_DEPTH_BUFFER_BIT = 0x00000100; B
	//GL_DEPTH_BUFFER_BIT = 0x00004100; A+B => GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	glActiveTexture(GL_TEXTURE0);
	GLuint timeLocataion = program.getUniformLocation("time");
	glUniform1f(timeLocataion, time);
	GLuint textureLocation = program.getUniformLocation("myImage");
	glUniform1f(textureLocation, 0);

	for (size_t i = 0; i < sprites.size(); i++) {
		sprites[i]->draw();
	}

	//sprite.draw();
	program.unuse();
	SDL_GL_SwapWindow(window);

}
