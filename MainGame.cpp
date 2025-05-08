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
			cout << "posicion x " << event.motion.x << " posicion y " << event.motion.y << endl;
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
	width = 800;
	height = 600;

	gameState = GameState::PLAY;

	init();
	sprite.init(-1, -1, 1, 1, "images/image.png");
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
	sprite.draw();
	program.unuse();
	SDL_GL_SwapWindow(window);

}
