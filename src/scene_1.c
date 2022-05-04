/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** scene_1
*/

#include "./../include/hunter.h"

s_scene1 init_scene1(s_scene1 scene)
{
    scene.bg_rect = (sfIntRect){0, 0, 660, 399};
    scene.bg_spr = sfSprite_create();
    scene.bg_scl = (sfVector2f){3.0, 3.0};
    scene.clock = sfClock_create();
    scene.sb_rect = (sfIntRect){0, 0, 260, 145};
    scene.sb_spr = sfSprite_create();
    scene.sb_scl = (sfVector2f){1.0, 1.0};
    scene.sb_pos = (sfVector2f){30, 240};

    return (scene);
}

s_game init_move_scene1(sfRenderWindow *window, s_game game, sfEvent event)
{
    game.scene1.bg_txt = sfTexture_createFromFile
    ("./sources/communist_stack_vertical.png", &game.scene1.bg_rect);
    sfSprite_setTexture(game.scene1.bg_spr, game.scene1.bg_txt, sfTrue);
    game.scene1.sb_txt = sfTexture_createFromFile
    ("./sources/output.png", &game.scene1.sb_rect);
    sfSprite_setTexture(game.scene1.sb_spr, game.scene1.sb_txt, sfTrue);
    game.scene1.time = sfClock_getElapsedTime(game.scene1.clock);
    game.scene1.seconds = game.scene1.time.microseconds / 1000000.0;
    if (game.scene1.seconds > 0.1) {
        game.scene1.bg_rect.left += 660;
        game.scene1.sb_rect.left += 260;
        sfClock_restart(game.scene1.clock);
    }
    if (game.scene1.bg_rect.left >= 4440) {
        game.scene1.bg_rect.left = 0;
    }
    if (game.scene1.sb_rect.left >= 520) {
        game.scene1.sb_rect.left = 0;
    }
    if (event.type == sfEvtMouseButtonPressed) {
        game.scn_counter = 1;
    }
    sfSprite_setScale(game.scene1.bg_spr, game.scene1.bg_scl);
    sfSprite_setPosition(game.scene1.sb_spr, game.scene1.sb_pos);
    sfRenderWindow_drawSprite(game.window.window, game.scene1.bg_spr, NULL);
    sfRenderWindow_drawSprite(game.window.window, game.scene1.sb_spr, NULL);
    return (game);
}
