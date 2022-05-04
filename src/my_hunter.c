/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myhunter-thomas.decaudain
** File description:
** my_runner
*/

#include "./../include/hunter.h"

s_window init_window(s_window window)
{
    sfVideoMode video_mode = {660, 399, 32};
    window.window = sfRenderWindow_create
    (video_mode, "my_hunter", sfClose | sfResize, NULL);
    return (window);
}

s_game (*display_game[2])
(sfRenderWindow *window, s_game game, sfEvent event) = {
    call_scene1,
    call_scene2,
};

int main(void)
{
    s_game game;
    game.window = init_window(game.window);
    game.scn_counter = 0;
    sfEvent event;

    game.scene1 = init_scene1(game.scene1);
    game.scene2 = init_scene2(game.scene2);

    sfMusic *menu_music = sfMusic_createFromFile("./sources/HymneRusse.ogg");
    sfMusic_play(menu_music);

    while (sfRenderWindow_isOpen(game.window.window)) {
        while (sfRenderWindow_pollEvent(game.window.window, &event)) {
            if (event.type == sfEvtClosed) {
                sfMusic_stop(menu_music);
                sfMusic_destroy(menu_music);
                sfRenderWindow_close(game.window.window);
            }
        }
        sfRenderWindow_display(game.window.window);
        game = display_game[game.scn_counter](game.window.window, game, event);
    }
    return (0);
}
