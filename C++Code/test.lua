--Script by Sirian142, in loving memory of Canada.

local module = {}

module.LicensePlateGenerator = function(plate, plateName)
    local random = Random.new()
    local character = nil
    local arraytype = "letters"
    local letters = ''
    local numbers = ''
    local licensePlate = ''
    local letterslist = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
    local numberslist = {'0','1','2','3','4','5','6','7','8','9'}
    local plateTypes = {'LicensePlate Normal','LicensePlate Commercial','LicensePlate Military','LicensePlate Green','LicensePlate Dealer','LicensePlate Diplomat'}


    local function getRandomL()
        character = letterslist[random:NextInteger(1,#letterslist)]
        return character
    end

    local function randomL(length)
        for i = 1, length do
            local random = getRandomL()
            letters = letters .. character
        end
        return letters
    end

    local function getRandomN()
        character = numberslist[random:NextInteger(1,#numberslist)]
        return character
    end
	
	local function randomN(length)
        for i = 1, length do
            local random = getRandomN()
            numbers = numbers .. character
        end
        return numbers
    end

    -- PLATE TYPES
    local function normalPlate()
        return (randomL(4).. "  " .. randomN(3))
    end

    local function commercialPlate()
        return (randomL(2).. "  " .. randomN(5))
    end

    local function dealerDiplomatPlate()
        return (randomL(3).. "  " .. randomN(3))
    end

    local function militaryPlate()
        return (randomN(5))
    end
    -- RUNNING CODE
    if plateName == plateTypes[2] then
        licensePlate = commercialPlate()
    elseif plateName == plateTypes[3] then
        licensePlate = militaryPlate()
    elseif plateName == plateTypes[5] or plateName == plateTypes[6] then
        licensePlate = dealerDiplomatPlate()
    elseif plateName == plateTypes[1] or plateName == plateTypes[4] then
        licensePlate = normalPlate()
    end
    return licensePlate
end

return module