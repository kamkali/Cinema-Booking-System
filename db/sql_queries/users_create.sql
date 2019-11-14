CREATE TABLE users(
    user_id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_name varchar[255]  NOT NULL,
    user_password varchar[255] NOT NULL,
    user_privileges varchar[255] NOT NULL,

    CONSTRAINT unique_username UNIQUE (user_name)
);
