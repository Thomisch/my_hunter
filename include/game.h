/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** game
*/

#ifndef _GAME_H_
    #define _GAME_H_

    #include "./hunter.h"

typedef struct window_t {
    sfVideoMode video_mode;
    sfRenderWindow *window;
} s_window;

typedef struct scene1_t {
    sfIntRect bg_rect;
    sfTexture *bg_txt;
    sfSprite *bg_spr;
    sfVector2f bg_scl;
    sfClock *clock;
    sfTime time;
    float seconds;

    sfIntRect sb_rect;
    sfTexture *sb_txt;
    sfSprite *sb_spr;
    sfVector2f sb_scl;
    sfVector2f sb_pos;
} s_scene1;

typedef struct ennemi_t {
    sfIntRect ss_rect;
    sfTexture *ss_txt;
    sfSprite *ss_spr;
    sfVector2f ss_scl;
    sfVector2f ss_pos;
    sfClock *clock;
    sfTime time;
    float seconds;
} s_ennemi;

typedef struct weapon_t {
    sfIntRect ws_rect;
    sfVector2f ws_scl;
    sfVector2f ws_pos;
    sfSprite *ws_spr;
    sfTexture *ws_txt;
    sfSoundBuffer *shot_buffer;
    sfSound *shot_sound;
    sfIntRect wr_rect;
    sfVector2f wr_scl;
    sfVector2f wr_pos;
    sfSprite *wr_spr;
    sfTexture *wr_txt;
    sfSoundBuffer *reload_buffer;
    sfSound *reload_sound;
    sfClock *clock_reload;
    sfTime time_reload;
    float rl_secs;
    sfClock *clock;
    sfTime time;
    float seconds;
} s_weapon;

typedef struct scene2_t {
    sfIntRect bg_rect;
    sfTexture *bg_txt;
    sfSprite *bg_spr;
    sfVector2f bg_scl;

    sfIntRect ovbg_rect;
    sfTexture *ovbg_txt;
    sfSprite *ovbg_spr;
    sfVector2f ovbg_scl;

    s_ennemi ennemy;
    s_weapon weapon;
    int score;
} s_scene2;

typedef struct scene3_t {
    sfIntRect bg_rect;
    sfTexture *bg_txt;
    sfSprite *bg_spr;
    sfVector2f bg_scl;
} s_scene3;

typedef struct game_t {
    short scn_counter;
    s_window window;
    s_scene1 scene1;
    s_scene2 scene2;
    s_scene3 scene3;
} s_game;

#endif/*_GAME_H_*/