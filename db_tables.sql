CREATE TABLE user(
    user_id INTEGER PRIMARY KEY NOT NULL,
    user_name varchar[255]  NOT NULL,
    user_password varchar[255] NOT NULL,
    user_privilages varchar[255] NOT NULL,

    CONSTRAINT unique_username UNIQUE (user_name) 
);


