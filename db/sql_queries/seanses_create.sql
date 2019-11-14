CREATE TABLE seanses(
    seans_id INTEGER PRIMARY KEY AUTOINCREMENT,
    seans_name VARCHAR[255] NOT NULL,
    movie_id INTEGER NOT NULL,

    FOREIGN KEY(movie_id) REFERENCES movie(movie_id),
    CONSTRAINT unique_seansname UNIQUE (seans_name)
);
