import React from "react";
import { createRoot } from "react-dom/client";
import "./styles/app.css";

const root = createRoot(document.getElementById("root"));

root.render(
  <React.StrictMode>
    <div>
      <h1>Monopoly Arcade</h1>
      <p>React renders UI only. Game logic lives on the server.</p>
    </div>
  </React.StrictMode>
);
