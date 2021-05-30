Here the last friend will have option to either to go alonr or with someone out of remaining n-1 friends.
so basically we've to compute sum of all the possibilities:
Recurrence-> f(n) = f(n-1) + (n-1)*f(n-2);