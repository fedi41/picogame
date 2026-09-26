print("Test")

function init()
    pos = { x = 10, y = 10}
    speed = 5
end

function update()
    if input.btn_down(4) then
        pos.y = pos.y - speed;
    end
    if input.btn_down(5) then
        pos.y = pos.y + speed;
    end
    if input.btn_down(6) then
        pos.x = pos.x - speed;
    end
    if input.btn_down(7) then
        pos.x = pos.x + speed;
    end
end

function draw()
    gfx.clear_screen(0x0000);
    gfx.fill_rect(pos.x, pos.y, 100, 100, 0xFF00);
end
