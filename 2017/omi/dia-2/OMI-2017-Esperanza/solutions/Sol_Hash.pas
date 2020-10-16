program Esperanza;

{$APPTYPE CONSOLE}

const
     NORTE    = 1;
     ESTE     = 2;
     SUR      = 3;
     OESTE    = 4;
     deltas : array [1..4,1..4,1..2] of integer = (((0,1), (-1,1), (1,1), (0,2)), ((1,0),(2,0),(1,-1),(1,1)), ((0,-1),(-1,-1),(1,-1),(0,-2)), ((-1,0),(-2,0),(-1,-1),(-1,1)));

     MAX_HASH   = 4000000;
     PRIMO_HASH = 2999999;
     JUMP_HASH  = 1;

type
    coord = record
       x, y : integer;
       sig : boolean;
    end;

var
   n, i, j, k, t, dir : integer;
   existe : boolean;
   c : char;
   x, y, dx, dy : integer;
   hash : array [0..MAX_HASH] of coord;

function calculaHash(x, y : integer) : integer;
var
   t : Int64;
begin
     t:=x * y;
     calculaHash:=t mod PRIMO_HASH;
end;

function sigIndHash(t : integer) : integer;
var
   t2 : integer;
begin
     t2:=t + JUMP_HASH;
     if t2 > MAX_HASH then t2:=t2 mod (MAX_HASH + 1);

     sigIndHash:=t2;
end;

procedure insertaHash(x, y : integer);
var
   t : integer;
begin
     t:=calculaHash(x, y);
     while hash[t].sig do begin
           t:=sigIndHash(t);
     end;

     if hash[t].x = -1 then begin
        hash[t].x:=x;
        hash[t].y:=y;
     end
     else begin
          hash[t].sig:=true;
          t:=sigIndHash(t);
          hash[t].x:=x;
          hash[t].y:=y;
     end;
end;

begin
     for i:=0 to MAX_HASH do begin
         hash[i].x:=-1;
         hash[i].sig:=false;
     end;

     readln(n);
     x:=n+1;
     y:=n+1;
     insertaHash(x,y);
     for i:=1 to n do begin
         read(c);
         case ord(c) of
              ord('U') : dir:=NORTE;
              ord('L') : dir:=OESTE;
              ord('R') : dir:=ESTE;
              ord('D') : dir:=SUR;
         end;

         for j:=1 to 4 do begin
             existe:=false;
             dx:=x + deltas[dir, j, 1];
             dy:=y + deltas[dir, j, 2];
             t:=calculaHash(dx, dy);
             if (hash[t].x = dx) and (hash[t].y = dy) then
                existe:=true;

             while hash[t].sig do begin
                   t:=sigIndHash(t);
                   if (hash[t].x = dx) and (hash[t].y = dy) then begin
                      existe:=true;
                      break;
                   end;
             end;

             if existe then break;
         end;

         if existe then begin
            writeln('N');
            halt(0);
         end
         else begin
              x:=x + deltas[dir, 1, 1];
              y:=y + deltas[dir, 1, 2];
              insertaHash(x, y);
         end;
     end;
     writeln('S');
end.
