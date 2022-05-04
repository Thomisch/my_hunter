/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** hunter
*/

#ifndef _HUNTER_H_
    #define _HUNTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <SFML/System/Clock.h>
    #include "./game.h"

s_scene1 init_scene1(s_scene1 scene);
s_game init_move_scene1(sfRenderWindow *window,
                        s_game game, sfEvent event);
s_scene2 init_scene2(s_scene2 scene);
s_ennemi init_s_ennemi(s_ennemi ennemy);
s_weapon init_s_weapon(s_weapon weapon);
s_scene2 init_move_scene2(sfRenderWindow *window,
                        s_scene2 scene, sfEvent event);
s_game call_scene1(sfRenderWindow *window, s_game game, sfEvent event);
s_game call_scene2(sfRenderWindow * window, s_game game, sfEvent event);
s_game (*display_game[2])(sfRenderWindow *window, s_game game, sfEvent event);

#endif/*_HUNTER_H_*/