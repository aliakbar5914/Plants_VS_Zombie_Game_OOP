# Zombie WarFrame – Tower Defense Game (C++ & SFML)

A thrilling tower defense game where sentient plants protect their world from waves of invading zombies! Inspired by the classic *Plants vs. Zombies*, this project uses **C++** and **SFML** to deliver engaging, level-based gameplay with dynamic graphics and interactive mechanics.

---

## Game Overview

In the lush world of **Verdantia**, peace is shattered by a zombie invasion. Brave plants rise to defend their home! As the player, you will:

- Place various **plants** on a grid to defend your base.
- Counter different types of **zombies** with strategic planning.
- Collect and manage **sunlight**, the in-game currency.
- Progress through **multiple levels**, each with unique challenges.

---

## Features

### Plants
- **Peashooter**: Fires one pea at intervals (100 sun).
- **Sunflower**: Generates sun every 10 seconds (100 sun).
- **Repeater**: Shoots two peas every 2 seconds (200 sun).
- **Wall-nut**: Rolls and blocks zombies (50 sun).
- **Snow Pea**: Slows zombies with frozen peas.
- **Cherry Bomb**: Destroys nearby zombies (150 sun).
- **Fume-shroom**: Sprays damaging fumes in a 4-tile range (75 sun).

### Zombies
- **Simple Zombie**: Basic, slow, 3-hit elimination.
- **Football Zombie**: Normal speed, helmet armor.
- **Flying Zombie**: Flies over defenses, cannot be blocked.
- **Dancing Zombie**: Moves diagonally and summons others.
- **Conehead Zombie**: Higher resistance than normal.

### Levels
1. **Beginner's Garden** – Basic intro with peashooters and sunflowers.
2. **Zombie Outskirts** – Stronger zombies and wall-nut unlocked.
3. **Sunflower Fields** – Focus on sunlight management.
4. **Foggy Forest** – Reduced visibility, adds difficulty.
5. **Nighttime Siege** – Low sun production, nocturnal plants.
6. **Rooftop Rampage** – Limited planting space, fast-paced waves.

---

## Screens & UI

- Game Menu  
- Instructions  
- Main Gameplay Screen  
- Pause Functionality  
- High Scores  
- End Screen

---

## File Handling

- Player names and high scores are stored in a file (`player_scores.txt`).
- Scores are sorted in **descending order** and persist between sessions.

---

## Tech Stack

- **C++**
- **SFML** (Graphics, Windowing, Audio)
- Object-Oriented Design (Inheritance, Polymorphism)
- Custom game loop and event handling

---

## Controls

- **Mouse**: Place plants, collect sunlight.
- **Keyboard**: Menu navigation, pause/resume.

---

