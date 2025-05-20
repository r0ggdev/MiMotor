#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
using namespace std;

TextureCache::TextureCache()
{
}

TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(string texturePath)
{
	map<string, GLTexture>::iterator ite = textureMap.find(texturePath);
	if (ite == textureMap.find(texturePath)) {
		cout << "Estoy cargando la imagen desde la ruta " << endl;
		GLTexture texture = ImageLoader::loadPNG(texturePath);
		textureMap[texturePath] = texture;
		return texture;
	}
	cout << "Estoy cargando desde la cache " << endl;

	return ite->second;
}
