//Time: 09.07.2025 12:00 a.m
#include "Deck.h"
#include "Hand.h"
#include "War.h"
#include <raylib.h>

int main() {
    // 1) Build & deal  
    Deck deck;  deck.shuffle();
    Hand p1, p2;
    while (!deck.empty()) {
        p1.placeBottom(deck.drawTop());
        if (!deck.empty()) p2.placeBottom(deck.drawTop());
    }

    War game(p1, p2);

    // 2) Init raylib window
    const int W = 800, H = 600;
    InitWindow(W, H, "War Card Game");
    SetTargetFPS(60);

    bool ongoing = true;
    // 3) Main loop: only step on SPACE
    while (ongoing && !WindowShouldClose()) {
        // Check for input once per frame
        if (IsKeyPressed(KEY_SPACE)) {
            // Advance exactly one round
            ongoing = game.playRound();
        }

        // Draw current state
        BeginDrawing();
        ClearBackground(DARKGREEN);

        // Draw instruction
        DrawText("Press SPACE to play next round", 50, 10, 20, LIGHTGRAY);

        // draw bars
        float frac1 = p1.size() / 52.0f;
        float frac2 = p2.size() / 52.0f;
        DrawRectangle(50, 80, int(700 * frac1), 30, GRAY);
        DrawRectangle(50, 140, int(700 * frac2), 30, GRAY);

        // labels
        DrawText(TextFormat("P1: %02d cards", p1.size()), 50, 50, 20, WHITE);
        DrawText(TextFormat("P2: %02d cards", p2.size()), 50, 110, 20, WHITE);

        // last face-up cards
        DrawText(game.lastCard1().name().c_str(), 50, 200, 20, YELLOW);
        DrawText(game.lastCard2().name().c_str(), 50, 230, 20, YELLOW);

        // stats
        DrawText(TextFormat("Rounds: %d   Wars: %d",
            game.getRounds(), game.getWars()),
            50, 280, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
