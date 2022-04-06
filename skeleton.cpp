/*
 * SDL2 skeleton for lab assignments 1–3 of the KTH course DH2323,
 * Computer Graphics and Interaction (and also SU DA3001, Datalogi II).
 *
 * See README.md for details.
 */

#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include "SDL2Auxiliary.h"

using namespace std;
using glm::vec3;

// --------------------------------------------------------
// GLOBAL VARIABLES

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL2Aux *sdlAux;

// --------------------------------------------------------
// FUNCTION DECLARATIONS

void Draw();
//void Interpolate( float a, float b, vector<float>& result );
void Interpolate( vec3 a, vec3 b, vector<vec3>& result );


// --------------------------------------------------------
// FUNCTION DEFINITIONS

int main(int argc, char* argv[]) {
  sdlAux = new SDL2Aux(SCREEN_WIDTH, SCREEN_HEIGHT);
  
    vector<vec3> result( 4 );
    vec3 a(1,4,9.2);
    vec3 b(4,1,9.8);
    Interpolate( a, b, result );
  
  //vector<float> result( 10 ); // Create a vector width 10 floats 
  //Interpolate( 5, 14, result ); // Fill it with interpolated values
  while (!sdlAux->quitEvent()) {
    Draw();  
  }
  
  sdlAux->saveBMP("screenshot.bmp");
  return 0;
}

void Interpolate( vec3 a, vec3 b, vector<vec3>& result ){
  float iterationsizex = (b.x-a.x)/(result.size()-1);
  float iterationsizey = (b.y-a.y)/(result.size()-1);
  float iterationsizez = (b.z-a.z)/(result.size()-1);
  float sumx = a.x;
  float sumy = a.y;
  float sumz = a.z;

  if (result.size() > 1)
  {
    for( int i=0; i<result.size(); ++i ){
    result[i].x = sumx;
    result[i].y = sumy;
    result[i].z = sumz;
      cout << "( "
      << result[i].x << ", "
      << result[i].y << ", "
      << result[i].z << " ) ";
    
  // cout << result[i] << " "; // Print the result to the terminal
    sumx = sumx + iterationsizex; 
    sumy = sumy + iterationsizey; 
    sumz = sumz + iterationsizez; 
    }
  }
}

void Draw() {
  sdlAux->clearPixels();
  vec3 topLeft(1,0,0); // red
  vec3 topRight(0,0,1); // blue
  vec3 bottomLeft(0,1,0); // green
  vec3 bottomRight(1,1,0); // yellow

  for (int y = 0; y < SCREEN_HEIGHT; ++y) {
    for (int x = 0; x < SCREEN_WIDTH; ++x) {
      vec3 color(0.0, 0.3, 0.7);
      sdlAux->putPixel(x, y, color);
    }
  }

  sdlAux->render();
}
