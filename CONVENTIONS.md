# Conventions

## C++

- Module: `Argo`. Class prefix: `SD` (Space Defender), on top of Unreal's type prefixes: `ASDShipPawn`, `USDHealthComponent`, `FSDWaveConfig`, `ESDEnemyRole`, `ISDDamageable`.
- Folders under `Source/Argo/`, one per feature, matching the content folders below: `Core/`, `Player/`, `Combat/`, `Enemies/`, `Waves/`, `Sectors/`, `Upgrades/`, `City/`, `Save/`, `Analytics/`, `UI/`.
- Gameplay logic in C++; Blueprints only subclass for tuning, assets and UI.
- Tunable data lives in DataAssets (`USDEnemyData`, `USDUpgradeData`, `USDSectorData`, `USDWeaponData`), never hardcoded.
- Cross-system communication through subsystems and delegates, not `GetAllActorsOfClass` or tag lookups.
- Log category per area: `LogArgo`, `LogArgoWaves`, `LogArgoSave`.

## Content folders

```
Content/Argo/
  Core/        GameMode, GameInstance, input
  Player/      ship, turret, shield
  Enemies/     one subfolder per enemy
  Combat/      projectiles, weapons, damage types
  Waves/       director config, wave data
  Sectors/     sector data, hazards, backgrounds
  Upgrades/
  City/
  UI/          widgets, HUD, icons
  VFX/         Niagara systems
  Audio/       SFX, music, sound classes
  Maps/
  Art/         shared meshes, materials, textures
Content/Developers/   personal test content, never referenced by game content
```

Third-party and marketplace packs stay in their own top-level folder, outside `Content/Argo/`.

## Asset prefixes

| Asset | Prefix | Example |
| --- | --- | --- |
| Blueprint | `BP_` | `BP_Ship` |
| Widget Blueprint | `WBP_` | `WBP_HUD` |
| Data Asset | `DA_` | `DA_Enemy_Raider` |
| Data Table | `DT_` | `DT_Upgrades` |
| Enum / Struct (BP) | `E_` / `F_` | `E_EnemyRole` |
| Input Action / Mapping Context | `IA_` / `IMC_` | `IA_Fire`, `IMC_Default` |
| Static Mesh | `SM_` | `SM_Ship_Hull` |
| Skeletal Mesh | `SK_` | `SK_Boss` |
| Material / Instance / Function | `M_` / `MI_` / `MF_` | `MI_Ship_Red` |
| Texture | `T_` + suffix | `T_Ship_D`, `T_Ship_N`, `T_Ship_ORM` |
| Niagara System / Emitter | `NS_` / `NE_` | `NS_Explosion_Small` |
| Sound Wave / Cue / MetaSound | `S_` / `SC_` / `MS_` | `MS_Laser` |
| Sound Class / Mix | `SCL_` / `SMX_` | `SCL_SFX` |
| Map | `L_` | `L_Arena`, `L_MainMenu` |
| Curve | `C_` | `C_WaveBudget` |

## Git

- `main` always builds and runs.
- Short-lived branches for bigger features: `feature/wave-director`.
- Commit messages in English, imperative mood: `Add pooled projectile component`.
- Binary assets go through Git LFS; check `git lfs status` before pushing large changes.
- Never commit `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/` or IDE files.
