# My Teams (Epitech Project)

> A collaborative workspace platform built in C with a TCP server, CLI client, custom application protocol, and event-driven concurrency using `poll()`.

![Language](https://img.shields.io/badge/language-C-blue)
![Platform](https://img.shields.io/badge/platform-Linux-lightgrey)
![Networking](https://img.shields.io/badge/network-TCP-green)
![Concurrency](https://img.shields.io/badge/concurrency-poll()-orange)

My Teams is a client-server collaborative communication platform inspired by modern team workspaces. It was developed as a systems programming project focused on low-level networking, protocol design, and event-driven server architecture in C.

The project implements hierarchical collaboration through teams, channels, threads, and replies, while also supporting direct messaging between users.

---

## Features

- Multi-client TCP server
- Interactive CLI client
- Teams and subscriptions
- Channels within teams
- Threaded discussions
- Thread replies
- Direct user-to-user messaging
- Persistent server state
- Context-aware command system
- Custom application protocol

---

## Architecture

```
                TCP
┌──────────────┐                  ┌────────────────┐
│ CLI Client A │ ◄──────────────► │                │
├──────────────┤                  │                │
│ CLI Client B │ ◄──────────────► │   My Teams     │
├──────────────┤                  │    Server      │
│ CLI Client C │ ◄──────────────► │  poll() loop   │
└──────────────┘                  └──────┬─────────┘
                                         │
                                         ▼
                                 Persistent Storage
```

The server uses an event-driven architecture based on `poll()`, allowing multiple clients to communicate simultaneously without relying on threads or `fork()`.

---

## Resource Model

```
Workspace
└── Team
    └── Channel
        └── Thread
            └── Reply
```

Users can also exchange private messages independently of the workspace hierarchy.

---

## Project Structure

```
src/
├── client/
│   ├── message/
│   ├── socket.c
│   └── client.c
│
├── server/
│   ├── client_connection/
│   ├── commands/
│   ├── create/
│   ├── error_handling/
│   └── queue/
│       ├── getters/
│       ├── inserters/
│       ├── store_lists/
│       └── upload_lists/
│
├── common/
│   ├── concat/
│   ├── parser.c
│   └── split_str.c
│
└── file_management/
    ├── read_file.c
    └── write_file.c
```

The project separates networking, command handling, shared utilities, and persistence into independent modules to keep both the client and server organized.

---

## Building

Compile the project:

```bash
make
```

Rebuild from scratch:

```bash
make re
```

---

## Running

### Linux shared library

The project uses the provided logging library (`libs/myteams/libmyteams.so`). Before running the binaries, set the library path for the current terminal session:

```bash
export LD_LIBRARY_PATH="$PWD/libs/myteams:$LD_LIBRARY_PATH"
```

Alternatively, you can prefix each command with `LD_LIBRARY_PATH=./libs/myteams`.

### Start the server

```bash
./myteams_server 4242
```

### Connect a client

```bash
./myteams_cli 127.0.0.1 4242
```

---

## CLI Commands

| Comando | Descrição |
| :--- | :--- |
| `/login ["user_name"]` | set the user_name used by client |
| `/logout` | disconnect the client from the server |
| `/users` | get the list of all users that exist on the domain |
| `/user ["user_uuid"]` | get details about the requested user |
| `/send ["user_uuid"] ["message_body"]` | send a message to specific user |
| `/messages ["user_uuid"]` | list all messages exchanged with the specified user |
| `/subscribe ["team_uuid"]` | subscribe to the events of a team and its sub directories (enable reception of all events from a team) |
| `/subscribed ?["team_uuid"]` | list all subscribed teams or list all users subscribed to a team |
| `/unsubscribe ["team_uuid"]` | unsubscribe from a team |
| `/use ?["team_uuid"] ?["channel_uuid"] ?["thread_uuid"]` | Sets the command context to a team/channel/thread |
| `/create` | based on the context, create the sub resource |
| `/list` | based on the context, list all the sub resources |
| `/info` | based on the context, display details of the current resource |

---

## Technical Highlights

This project demonstrates practical experience with:

- C programming
- TCP socket programming
- Event-driven server design
- I/O multiplexing with `poll()`
- Client-server architecture
- Custom application protocol design
- Persistent state management
- Command parsing
- Modular software organization

---

## About

This repository preserves the original implementation developed as an academic systems programming project and serves as a portfolio showcase of networking and low-level software engineering concepts.
