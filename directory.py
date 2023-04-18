def sort_people(people):
    return sorted(people, key = lambda x: (int(x.birth_date.split(".")[2]), 
                                           int(x.birth_date.split(".")[1]),
                                           int(x.birth_date.split(".")[0]),
                                           x.last_name,
                                           x.first_name))

      