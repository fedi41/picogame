#ifndef INPUT_H
#define INPUT_H

enum BUTTONS {
    BTN_A,
    BTN_B,
    BTN_X,
    BTN_Y,
    BTN_UP,
    BTN_DOWN,
    BTN_LEFT,
    BTN_RIGHT,
};

// For the Gamepad detections etc
int init_inputs();
int is_btn_pressed(int btn);
int is_btn_down(int btn);
int deinit_inputs();

#endif
