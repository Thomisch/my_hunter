/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** inits_scene2
*/

#include "./../include/hunter.h"

s_ennemi init_s_ennemi(s_ennemi ennemy)
{
    ennemy.ss_rect = (sfIntRect){1, 1, 46, 46};
    ennemy.ss_spr = sfSprite_create();
    ennemy.ss_scl = (sfVector2f){2.0, 2.0};
    ennemy.ss_pos = (sfVector2f){0.0, 30.0};
    ennemy.clock = sfClock_create();

    return (ennemy);
}

s_weapon init_s_weapon(s_weapon weapon)
{
    weapon.ws_scl = (sfVector2f){3.5, 3.5};
    weapon.ws_rect = (sfIntRect){0, 0, 600, 480};
    weapon.ws_pos = (sfVector2f){156, 0};
    weapon.shot_buffer = sfSoundBuffer_createFromFile
    ("./sources/ak-sound.wav");
    weapon.shot_sound = sfSound_create();
    sfSound_setBuffer(weapon.shot_sound, weapon.shot_buffer);
    weapon.ws_spr = sfSprite_create();
    weapon.clock = sfClock_create();

    weapon.wr_scl = (sfVector2f){3.5, 3.5};
    weapon.wr_rect = (sfIntRect){0, 0, 600, 480};
    weapon.wr_pos = (sfVector2f){156, 0};
    weapon.reload_buffer = sfSoundBuffer_createFromFile
    ("./sources/reload.wav");
    weapon.reload_sound = sfSound_create();
    sfSound_setBuffer(weapon.reload_sound, weapon.reload_buffer);
    weapon.wr_spr = sfSprite_create();
    weapon.clock_reload = sfClock_create();

    return (weapon);
}
