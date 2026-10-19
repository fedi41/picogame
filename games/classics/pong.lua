local paddle1 = {
   x = 10,
   y = 95,
   w = 10,
   h = 50
}
local paddle2 = {
   x = 240 - 10 - 10,
   y = 95,
   w = 10,
   h = 50
}
local ball = {
   x = 115,
   y = 115,
   w = 10,
   h = 10
}
local velocity = {
   x = 150,
   y = 150
}
local speed = 250
local screen_h = 240
local screen_w = 240

local function check_collision(a, b)
    return a.x < b.x + b.w and
           a.x + a.w > b.x and
           a.y < b.y + b.h and
           a.y + a.h > b.y
end

function check_ball_wall()
   if ball.x + ball.w > screen_w or ball.x < 0 then
      velocity.x = -velocity.x
   end
   if ball.y + ball.h > screen_h or ball.y < 0 then
      velocity.y = -velocity.y
   end
end

function init() end

function update(dt)
   ball.x = ball.x + velocity.x * dt
   ball.y = ball.y + velocity.y * dt
   
   check_ball_wall()

   if check_collision(ball, paddle1) or check_collision(ball, paddle2) then
      velocity.x = -velocity.x
   end

   if input.btn_down(4) then paddle1.y = paddle1.y - speed * dt end
   if input.btn_down(5) then paddle1.y = paddle1.y + speed * dt end

   if input.btn_down(1) then paddle2.y = paddle2.y + speed * dt end
   if input.btn_down(2) then paddle2.y = paddle2.y - speed * dt end

   paddle1.y = math.max(0, math.min(screen_h - paddle1.h, paddle1.y))
   paddle2.y = math.max(0, math.min(screen_h - paddle2.h, paddle2.y))
end

function draw()
   gfx.clear_screen(0x0000);
   gfx.fill_rect(math.floor(ball.x), math.floor(ball.y), ball.w, ball.h, 0xffff)
   gfx.fill_rect(math.floor(paddle1.x), math.floor(paddle1.y), paddle1.w, paddle1.h, 0xffff)
   gfx.fill_rect(math.floor(paddle2.x), math.floor(paddle2.y), paddle2.w, paddle2.h, 0xffff)
end
