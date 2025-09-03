#include <gba.h>
#include "battle.h"

void startBattle(void) {
    consoleDemoInit();
    iprintf("A wild enemy appears!\n");
    iprintf("Press A to attack, B to run\n");

    int enemyHP = 20;

    while (enemyHP > 0) {
        scanKeys();
        u16 keys = keysDown();

        if (keys & KEY_A) {
            enemyHP -= 5;
            iprintf("You hit enemy! HP: %d\n", enemyHP);
        }
        if (keys & KEY_B) {
            iprintf("You ran away!\n");
            break;
        }

        VBlankIntrWait();
    }
}
