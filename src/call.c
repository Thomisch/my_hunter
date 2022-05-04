/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** call
*/

#include "./../include/hunter.h"

s_game call_scene1(sfRenderWindow *window, s_game game, sfEvent event)
{
    game = init_move_scene1(window, game, event);
    return (game);
}

s_game call_scene2(sfRenderWindow * window, s_game game, sfEvent event)
{
    game.scene2 = init_move_scene2(window, game.scene2, event);
    return (game);
}
