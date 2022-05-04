/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** scene_2
*/

#include "./../include/hunter.h"

s_scene2 init_scene2(s_scene2 scene)
{
    scene.bg_txt = sfTexture_createFromFile
    ("./sources/Gefechtsfeld_Hartmannsweilerkopf.png", NULL);
    scene.bg_spr = sfSprite_create();
    sfSprite_setTexture(scene.bg_spr, scene.bg_txt, sfTrue);
    sfVector2f bg_scl = (sfVector2f){0.7, 0.6};
    sfSprite_setScale(scene.bg_spr, bg_scl);

    scene.ovbg_txt = sfTexture_createFromFile
    ("./sources/Gefechtsfeld_Hartmannsweilerkopf-removebg-preview.png", NULL);
    scene.ovbg_spr = sfSprite_create();
    sfSprite_setTexture(scene.ovbg_spr, scene.ovbg_txt, sfTrue);
    sfVector2f ovbg_scl = (sfVector2f){1.16, 1.0};
    sfSprite_setScale(scene.ovbg_spr, ovbg_scl);

    scene.ennemy = init_s_ennemi(scene.ennemy);
    scene.weapon = init_s_weapon(scene.weapon);

    scene.score = 0;

    return (scene);
}

s_ennemi anim_perso_move(s_ennemi ennemy)
{
    ennemy.ss_txt = sfTexture_createFromFile
    ("./sources/Guard_with_swastika_armband_off-removebg-preview(1).png",
    &ennemy.ss_rect);
    sfSprite_setTexture(ennemy.ss_spr, ennemy.ss_txt, sfTrue);
    ennemy.time = sfClock_getElapsedTime(ennemy.clock);
    ennemy.seconds = ennemy.time.microseconds / 1000000.0;
    if (ennemy.seconds > 0.1) {
        ennemy.ss_pos.x += 6;
        ennemy.ss_pos.y += 2;
        ennemy.ss_rect.top += 47;
        sfClock_restart(ennemy.clock);
    }
    if (ennemy.ss_rect.top >= 188) {
        ennemy.ss_rect.top = 1;
    }
    return (ennemy);
}

s_weapon anim_weapon(s_weapon weapon, sfEvent event)
{
    weapon.ws_txt = sfTexture_createFromFile
    ("./sources/weapon-shot.png", &weapon.ws_rect);
    sfSprite_setTexture(weapon.ws_spr, weapon.ws_txt, sfTrue);
    weapon.time = sfClock_getElapsedTime(weapon.clock);
    weapon.seconds = weapon.time.microseconds / 1000000.0;

    if (event.type == sfEvtMouseButtonPressed) {
        if (weapon.seconds > 0.1) {
            weapon.ws_rect.top += 480;
            weapon.time = sfClock_restart(weapon.clock);
        }
        if (weapon.ws_rect.top >= 1) {
            sfSound_play(weapon.shot_sound);
        }
        if (weapon.ws_rect.top >= 1079) {//|| event.type == sfEvtMouseButtonReleased) {
            weapon.ws_rect.top = 0;
        }
    }
    if (event.type == sfEvtMouseButtonReleased && weapon.ws_rect.top != 0) {
        weapon.ws_rect.top = 0;
    }
    return (weapon);
}

sfBool checkif_ss_survived(sfVector2f pos, int x, int y)
{
    if (x >= pos.x && x <= pos.x + 92 && y >= pos.y && y <= pos.y + 92) {
        return (sfTrue);
    } else {
        return (sfFalse);
    }
}

s_scene2 init_move_scene2(sfRenderWindow *window,
s_scene2 scene, sfEvent event)
{
    sfVector2i mouse_pos;

    scene.ennemy = anim_perso_move(scene.ennemy);
    scene.weapon = anim_weapon(scene.weapon, event);

    sfRenderWindow_drawSprite(window, scene.bg_spr, NULL);

    sfSprite_setScale(scene.ennemy.ss_spr, scene.ennemy.ss_scl);
    sfSprite_setPosition(scene.ennemy.ss_spr, scene.ennemy.ss_pos);
    sfRenderWindow_drawSprite(window, scene.ennemy.ss_spr, NULL);

    sfRenderWindow_drawSprite(window, scene.ovbg_spr, NULL);

    sfSprite_setScale(scene.weapon.ws_spr, scene.weapon.ws_scl);
    sfSprite_setPosition(scene.weapon.ws_spr, scene.weapon.ws_pos);
    sfRenderWindow_drawSprite(window, scene.weapon.ws_spr, NULL);

    if (event.type == sfEvtMouseButtonPressed) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfVector2f spr_pos = sfSprite_getPosition(scene.ennemy.ss_spr);
        if (checkif_ss_survived(scene.ennemy.ss_pos, mouse_pos.x, mouse_pos.y)
            == sfFalse) {
            sfSprite_setScale(scene.weapon.wr_spr, scene.weapon.wr_scl);
            sfSprite_setPosition(scene.weapon.wr_spr, scene.weapon.wr_pos);
            sfRenderWindow_drawSprite(window, scene.weapon.wr_spr, NULL);
        } else if (checkif_ss_survived(scene.ennemy.ss_pos,
            mouse_pos.x, mouse_pos.y) == sfTrue) {
            scene.ennemy.ss_pos.x = -10;
            scene.ennemy.ss_pos.y = 30;
            scene.score += 1;
        }
    }
    return (scene);
}