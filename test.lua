print("Test")

function init()
    pos = { x = 10, y = 10}
end

function update()
    pos.x = pos.x + 1
end

function draw()
    gfx.fill_rect(10, 10, 100, 100, 0xFF00);
end
