vim.keymap.set("n", "<F5>", "<cmd>!cargo run -- --print-ast<CR>", { desc = "Run the app" })
vim.keymap.set("n", "<leader>bb", "<cmd>!cargo build<CR>", { desc = "Run the app" })
