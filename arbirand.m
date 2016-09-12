function out = arbirand(p,n)
    %out=drnd(p,n)
    %copyright: rocwoods
    %p is the probility distribution vector
    %n is the num of samples you hope to generate
    a = cumsum( p(2,:) )
    b = rand(n, 1)
    out =zeros(1, n);
    for k = 1:n
        c = find( a<b(k) )
        if (isempty(c))
            out(k)=p(1, 1);
        else
            out(k)=p(1, c(end)+1);
        end
    end