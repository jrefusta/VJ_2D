#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"
#include <string>
#include <iostream>
using namespace std;

void Game::init()
{
	bPlay = true;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	scene = new Menu();
	scene->init(0);
}

bool Game::update(int deltaTime)
{
	scene->update(deltaTime);
	
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	scene->render();
}

void Game::keyPressed(int key)
{
	//if(key == 27) // Escape code
		//bPlay = false;
	keys[key] = true;
}

void Game::keyReleased(int key) 
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;
}

void Game::exit() {
	bPlay = false;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}
bool Game::moveUpPressed() {
	return
		getSpecialKey(GLUT_KEY_UP) ||
		getKey(87) ||
		getKey(119);
}

bool Game::moveDownPressed() {
	return
		getSpecialKey(GLUT_KEY_DOWN) ||
		getKey(83) ||
		getKey(115);
}

bool Game::moveRightPressed() {
	return
		getSpecialKey(GLUT_KEY_RIGHT) ||
		getKey(68) ||
		getKey(100);
}
bool Game::moveLeftPressed() {
	return
		getSpecialKey(GLUT_KEY_LEFT) ||
		getKey(65) ||
		getKey(97);
}
void Game::selectScene(int ID) {
	delete scene;
	switch (ID) {
		case 0:
			scene = new Menu();
			scene->init(0);
			break;
		case 1:
			scene = new Play();
			scene->init(0);
			break;
		case 2:
			scene = new Help();
			scene->init();
			break;
		case 3: 
			scene = new Credits();
			scene->init();
			break;
		default:
			scene = new Level();
			scene->init();
			//scene->init(ID-4);
			break;
	}
}