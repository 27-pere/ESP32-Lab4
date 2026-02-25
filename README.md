# ESP32-Lab4

Members
- [Ampere](https://github.com/27-pere)
- [Karn](https://github.com/29Kn16)
- [Joan](https://github.com/67991033-cell)

2/25/2026
Lab work 4 Project Kosen

This project aims to
- know basic ESP-32
- connect ESP-32 with LED and use the touch detection function
- connect ESP-32 with SHT-21 to use for temperature and humidity measurement

Flowchart for Web.html

     ┌─────────────┐
     │ Page Loads  │
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │ Click Connect
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │ Read Serial │
     │ Data Loop   │
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │ T < 300?    │
     └──┬──────┬──┘
      Yes│    No│
        ▼      ▼
     ┌────┐  ┌────┐
     │LED │  │LED │
     │ ON │  │ OFF│
     └──┬─┘  └──┬─┘
        │       │
        └───┬───┘
            ▼
     ┌─────────────┐
     │Update Charts│
     └──────┬──────┘
            │
            └──→ Loop back


Flowchart for ESP-32

     ┌─────────────┐
     │ ESP32 Start │
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │   Setup()   │
     │ Init Sensors│
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │   Loop()    │ ← Loop back
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │ Read Touch  │
     │ Read Temp   │
     │ Read Humid  │
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │Send Serial: │
     │T,Temp,Humid│
     └──────┬──────┘
            │
            ▼
     ┌─────────────┐
     │ T < 300?    │
     └──┬──────┬──┘
      Yes│    No│
        ▼      ▼
     ┌────┐  ┌────┐
     │LED │  │LED │
     │ ON │  │ OFF│
     └──┬─┘  └──┬─┘
        │       │
        └───┬───┘
            ▼
     ┌─────────────┐
     │ Wait 1 sec  │
     └──────┬──────┘
            │
            └──→ Loop back
