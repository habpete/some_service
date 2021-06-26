CREATE TABLE IF NOT EXISTS public.events (
    id SERIAL;
    user_id bigint;
    messagetype_id bigint;
    created_time timestamp;
);

CREATE INDEX IF NOT EXISTS userid_idx ON public.events user_id;
CREATE INDEX IF NOT EXISTS messagetype_idx ON public.events messagetype_id;

CREATE TABLE IF NOT EXISTS public.users (
    id SERIAL;
    firstname nvarchar(30);
    secondname nvarchar(30);
    lastname nvarchar(30);
    phone nvarchar(15);
    email nvarchar(50);
);

CREATE TABLE IF NOT EXISTS public.message_types (
    id SERIAL;
    typename nvarchar(100);
);