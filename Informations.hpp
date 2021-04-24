#pragma once
#include <thread>


/*
* /\/\/\/\/\/\/\/\/\/\/\/\
* /\ MAP INFORMATION /\
* /\/\/\/\/\/\/\/\/\/\/\/\
*/
const unsigned int MAP_SIZE_X = 3200;
const unsigned int MAP_SIZE_Y = 3200;

/*
* /\/\/\/\/\/\/\/\/\/\/\/\
* /\ FRAME INFORMATION /\
* /\/\/\/\/\/\/\/\/\/\/\/\
*/
const unsigned int FRAME_SIZE = 32;
const unsigned int SPRITE_SIZE = 32;

const unsigned int TWO_POWER_OF_TWO = 4;
const unsigned int TWO_POWER_OF_THREE = 8;

/*
* /\/\/\/\/\/\/\/\/\/\/\/\
* /\ THREADING INFO /\
* /\/\/\/\/\/\/\/\/\/\/\/\
*/

const unsigned int hardware_threads_count = std::max(1u, std::thread::hardware_concurrency());