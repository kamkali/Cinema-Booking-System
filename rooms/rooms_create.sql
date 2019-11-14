CREATE TABLE rooms(
    room_id INTEGER PRIMARY KEY AUTOINCREMENT,
    room_name VARCHAR[255],
    seans_id INTEGER,
    seans_name VARCHAR[255],

    FOREIGN KEY(seans_id) REFERENCES seans(seans_id),
    CONSTRAINT unique_roomname UNIQUE (room_name)
);
