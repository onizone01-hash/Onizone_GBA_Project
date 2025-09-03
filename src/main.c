#include <gba.h>
#include "main.h"
#include "battle.h"
#include "npc.h"

int hunger = 100;
int playerX = 10, playerY = 10;

void checkInput(void) {
    scanKeys();
    u16 keys = keysDown();

    if (keys & KEY_UP) playerY--;
    if (keys & KEY_DOWN) playerY++;
    if (keys & KEY_LEFT) playerX--;
    if (keys & KEY_RIGHT) playerX++;

    if (keys & KEY_START) {
        // กินอาหาร
        hunger += 20;
        if (hunger > 100) hunger = 100;
    }
}

int main(void) {
    irqInit();
    irqEnable(IRQ_VBLANK);

    consoleDemoInit();

    iprintf("Onizone GBA Demo\n");
    iprintf("Use D-Pad to move\n");
    iprintf("Press START to eat\n");

    while (1) {
        VBlankIntrWait();
        checkInput();

        hunger--;
        if (hunger < 0) hunger = 0;

        iprintf("\x1b[10;0HHunger: %d   ", hunger);
        iprintf("\x1b[12;0HPos: (%d,%d)   ", playerX, playerY);

        // สุ่มเจอศัตรูเวลาเดิน
        if ((rand() % 200) == 0) {
            startBattle();
        }
    }
}
