#include "fps_counter.h"

FPSCounter::FPSCounter() : frame_counter(0) {

}

FPSCounter::~FPSCounter() {
	//die
}

void FPSCounter::count(float delta) {
	frame_times[frame_counter] = delta;
	frame_counter = (frame_counter + 1) % NUM_FRAMES_SAMPLED;
}

float FPSCounter::get_average() {
	float sum = 0;
	for(int i = 0; i < NUM_FRAMES_SAMPLED; i++) {
		sum += frame_times[i];
	}
	return 1 / (sum / NUM_FRAMES_SAMPLED);
}