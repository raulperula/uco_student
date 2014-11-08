%PADDING An example of padding.
%
% Syntax
%
%    padding
%

% Raul Perula-Martinez
% $License: GPL v3 $
% $Revision: 1.0 $  $Date: 2014-11 $

% FA(A) = 8192i+j
% FA(B) = i+8192j

% calc padding for L1 cache

w = 8;
C = 64;

strideAi = 8192;
strideAj = 1;

strideBi = 1;
strideBj = 8192;

if strideAi == 1
    incStrideAi = 1;
else
    incStrideAi = mod(strideAi/w,C);
    betai = gcd(incStrideAi,C);

    if betai ~= 1
        incStrideAi = incStrideAi+1;
    end;
end;

if strideBi == 1
    incStrideBi = 1;
else
    incStrideBi = mod(strideBi/w,C);
    betai = gcd(incStrideBi,C);

    if betai ~= 1
        incStrideBi = incStrideBi+1;
    end;
end;

if strideAj == 1
    incStrideAj = 1;
else
    incStrideAj = mod(strideAj/w,C);
    betaj = gcd(incStrideAj,C);

    if betaj ~= 1
        incStrideAj = incStrideAj+1;
    end;
end;

if strideBj == 1
    incStrideBj = 1;
else
    incStrideBj = mod(strideBj/w,C);
    betaj = gcd(incStrideBj,C);

    if betaj ~= 1
        incStrideBj = incStrideAj+1;
        strideBj = strideBj+w;
    end;
end;

'CACHE L1'
incStrideAi
incStrideAj

strideAi
strideAj

incStrideBi
incStrideBj

strideBi
strideBj

% calcular padding para caché L2

w = 8;
C = 4092;

strideAi = 8192;
strideAj = 1;

strideBi = 1;
strideBj = 8192;

if strideAi == 1
    incStrideAi = 1;
else
    incStrideAi = mod(strideAi/w,C);
    betai = gcd(incStrideAi,C);

    if betai ~= 1
        incStrideAi = incStrideAi+1;
    end;
end;

if strideBi == 1
    incStrideBi = 1;
else
    incStrideBi = mod(strideBi/w,C);
    betai = gcd(incStrideBi,C);

    if betai ~= 1
        incStrideBi = incStrideBi+1;
    end;
end;

if strideAj == 1
    incStrideAj = 1;
else
    incStrideAj = mod(strideAj/w,C);
    betaj = gcd(incStrideAj,C);

    if betaj ~= 1
        incStrideAj = incStrideAj+1;
    end;
end;

if strideBj == 1
    incStrideBj = 1;
else
    incStrideBj = mod(strideBj/w,C);
    betaj = gcd(incStrideBj,C);

    if betaj ~= 1
        incStrideBj = incStrideBj+1;
    end;
end;

'CACHE L2'
incStrideAi
incStrideAj

strideAi
strideAj

incStrideBi
incStrideBj

strideBi
strideBj
