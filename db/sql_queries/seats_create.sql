CREATE TABLE seats(seat_id INTEGER PRIMARY KEY AUTOINCREMENT,
                   room_id INTEGER NOT NULL,
                   user_id INTEGER,
                   number_in_room INTEGER,

                   FOREIGN KEY(room_id) REFERENCES rooms(room_id),
                   FOREIGN KEY(user_id) REFERENCES users(user_id)
                  )