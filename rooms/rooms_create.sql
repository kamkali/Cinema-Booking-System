CREATE TABLE rooms(
    room_id INTEGER PRIMARY KEY AUTOINCREMENT,
    seans_id INTEGER,
    seans_name VARCHAR[255]

    FOREIGN KEY(seans_id) REFERENCES seans(seans_id)
);
