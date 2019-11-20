CREATE TABLE movies(
                      movie_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                      title varchar[255]  NOT NULL,
                      director varchar[255] NOT NULL,
                      production_year integer NOT NULL,
                      price integer NOT NULL,
                      movie_length real NOT NULL,
                      movie_description VARCHAR[255]
);