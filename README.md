# Space Defender: Last City

**Codename: Argo** · Unreal Engine 5.8 · C++ · Solo project · November 2026

Escort humanity's last city, a colony ship traveling through space, as space pirates attack it sector after sector. Between waves, choose your route and whether to strengthen your ship or the city. Runs last 10–15 minutes.

## Why a remake

In 2019 I made [Space Defender](https://palicron.itch.io/space-defender) in Unity for **Mini Jam 24: Space**. You piloted a defender ship protecting the last human city from space pirates. Players liked the visuals, but the feedback was clear: the controls felt clunky, movement was slow and collisions were unreliable. I ran out of time to playtest.

Years later, with professional experience in UE5 C++ gameplay, I'm rebuilding it from scratch to finish what the jam version started. The goal is to keep the original's identity (defend the base, the shield, the pirates) and fix what didn't work:

| Original (Unity, 2019) | Remake (UE5, 2026) |
| --- | --- |
| Ship faces the mouse, right-click thrusts forward | Screen-relative twin-stick movement with arcade acceleration |
| Fighter that fires only forward | Redesigned gunship with a 360° turret |
| Transform-moved trigger bullets (tunneling) | Pooled, swept projectiles |
| Shield toggled the player collider off | Shield with energy that blocks and reflects |
| Fixed spawners, flat difficulty | Budget-driven wave director and a difficulty curve |
| Static base | A colony city traveling through space, with route choice between sectors |

This repo is also a before-and-after: the [original jam page](https://palicron.itch.io/space-defender) stays untouched, and the remake will get its own itch.io page that links back to it.

## Features (v1 scope)

- **Twin-stick shooting** with mouse/keyboard and gamepad
- **Wave defense roguelite:** pick 1 of 3 upgrades after each wave (ship, city or cursed)
- **Route choice:** choose the next sector (asteroid field, nebula, pirate territory, mine field…) with visible risk and reward
- **Procedural waves** driven by a difficulty budget and a run seed
- **Pirate enemies:** raiders, hunters, snipers, kamikazes, carriers and a pirate flagship boss
- **Meta progression** saved between runs
- **Analytics** for balancing (local JSON, optional GameAnalytics)
- **Readable threats:** off-screen indicators, city-centered radar, telegraphed attacks

## Tech

- Unreal Engine 5.8, gameplay in C++, data in DataAssets, Blueprints for UI and tuning
- Single-player, no replication
- Subsystems for run state, waves, upgrades, save and analytics
- Git LFS for binary assets (see `.gitattributes`)

## Status

In development, November 2026 (4-week plan):

1. Core feel in grey-box
2. Run structure, waves, upgrades and sectors
3. Save, analytics, HUD and game feel
4. Balance, art pass and release on itch.io

## Getting started

1. Install Unreal Engine 5.8 and Visual Studio 2022 (Game development with C++).
2. Install [Git LFS](https://git-lfs.com) and run `git lfs install` once.
3. Clone the repo, right-click `Argo.uproject` → *Generate Visual Studio project files*, then build and open.
