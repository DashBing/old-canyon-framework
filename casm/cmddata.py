cmd_data = {
    "MOV":{
        "low":{
            ["i8", "res8A"]:0x1,
            ["i64", "res64A"]:0x2,
            ["res8A", "res8B"]:0x5,
            ["res64A", "res64B"]:0x6,
        },
        "high":{
            ["mem", "res8A"]:[
                {
                    "args":["mem"],
                    "command":"L_MOV_FM {mem}",
                },
                {
                    "args":["res8A"],
                    "command":"MOV DE {res8A}",
                },
            ],
            ["res8A", "mem"]:[
                {
                    "args":["res8A"],
                    "command":"MOV {res8A} DE",
                },
            ],
        },
    },
    "L_MOV_FM":{"low":{["mem"]:0x3}},
    "L_MOV_TM":{"low":{["mem"]:0x4}},
}
