CREATE VIEW events_view AS
    SELECT e.id, mt.typename, u.firstname, u.secondname, u.lastname, u.phone, u.email, e.created_time FROM public.events AS e
    LEFT JOIN public.users AS u ON u.id = e.user_id
    LEFT JOIN public.message_types AS mt ON mt.id = e.messagetype_id